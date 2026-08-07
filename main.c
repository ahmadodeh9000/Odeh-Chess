/**
 * @author: Ahmad Odeh
 * @about: A simple 2D chess game in SDL2
 */

#include "common.h"
#include "chess.h"

static void print_status(game_status_t status, bool white_turn)
{
    switch (status) {
        case GAME_CHECKMATE:
            printf("CHECKMATE - %s wins!\n",
                   white_turn ? "Black" : "White");
            break;

        case GAME_STALEMATE:
            printf("STALEMATE - draw.\n");
            break;

        case GAME_CHECK:
            printf("%s is in check!\n",
                   white_turn ? "White" : "Black");
            break;

        default:
            break;
    }
}

static bool mouse_to_square(int mouse_x, int mouse_y,
                             int *square_x, int *square_y)
{
    const int square_width  = CHESS_GAME_WIDTH / 8;
    const int square_height = CHESS_GAME_HEIGHT / 8;

    /* Ignore clicks outside the chess board. */
    if (mouse_x < 0 || mouse_x >= CHESS_GAME_WIDTH ||
        mouse_y < 0 || mouse_y >= CHESS_GAME_HEIGHT) {
        return false;
    }

    *square_x = mouse_x / square_width;
    *square_y = mouse_y / square_height;

    /* Extra safety. */
    if (*square_x < 0 || *square_x >= 8 ||
        *square_y < 0 || *square_y >= 8) {
        return false;
    }

    return true;
}


static void draw_selection_highlight(SDL_Renderer *renderer,
                                      bool piece_selected,
                                      int selected_x,
                                      int selected_y)
{
    if (!piece_selected) {
        return;
    }

    const int tile_w = CHESS_GAME_WIDTH / 8;
    const int tile_h = CHESS_GAME_HEIGHT / 8;

    SDL_Rect highlight = {
        selected_x * tile_w,
        selected_y * tile_h,
        tile_w,
        tile_h
    };

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xD7, 0x00, 0xFF); /* gold */

    /* Draw a few nested rects for a thicker border instead of a 1px line. */
    for (int inset = 0; inset < 3; ++inset) {
        SDL_Rect r = {
            highlight.x + inset,
            highlight.y + inset,
            highlight.w - inset * 2,
            highlight.h - inset * 2
        };
        SDL_RenderDrawRect(renderer, &r);
    }
}

int main(void)
{


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        CHESS_ERR_LOG("SDL2 FAILED");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        CHESS_NAME,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        CHESS_GAME_WIDTH,
        CHESS_GAME_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL) {
        CHESS_ERR_LOG("SDL2 WINDOW FAILED");
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == NULL) {
        CHESS_ERR_LOG("SDL2 RENDERER FAILED");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }



    chess_t *chess_game = init_chess_board();

    if (chess_game == NULL) {
        CHESS_ERR_LOG("CHESS LOGIC FAILED");

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    }



    bool is_game_running = true;
    bool game_over = false;
    bool piece_selected = false;

    bool white_turn = true;

    int selected_x = -1;
    int selected_y = -1;

    SDL_Event event;



    print_chess_board_on_console(chess_game);

    game_status_t initial_status =
        get_game_status(chess_game, white_turn);

    print_status(initial_status, white_turn);

    if (initial_status == GAME_CHECKMATE ||
        initial_status == GAME_STALEMATE) {
        game_over = true;
    }


    while (is_game_running) {



        while (SDL_PollEvent(&event)) {

            /* Window close button. */
            if (event.type == SDL_QUIT) {
                is_game_running = false;
                continue;
            }

            /* Escape quits the game. */
            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {

                is_game_running = false;
                continue;
            }

            /* Don't accept game input after the game ends. */
            if (game_over) {
                continue;
            }

            /* Only handle left mouse button. */
            if (event.type == SDL_MOUSEBUTTONDOWN &&
                event.button.button == SDL_BUTTON_LEFT) {

                int x;
                int y;

                if (!mouse_to_square(
                        event.button.x,
                        event.button.y,
                        &x,
                        &y)) {
                    continue;
                }


                if (!piece_selected) {

                    selected_x = x;
                    selected_y = y;

                    piece_selected = true;
                }

                else if (x == selected_x && y == selected_y) {

                    piece_selected = false;
                    selected_x = -1;
                    selected_y = -1;
                }

                else {

                    bool move_successful = try_move_piece(
                        chess_game,
                        selected_x,
                        selected_y,
                        x,
                        y,
                        white_turn
                    );

                    piece_selected = false;
                    selected_x = -1;
                    selected_y = -1;

                    if (!move_successful) {
                        continue;
                    }



                    white_turn = !white_turn;

                    clear_console();
                    print_chess_board_on_console(chess_game);

                    game_status_t status =
                        get_game_status(chess_game, white_turn);

                    print_status(status, white_turn);

                    if (status == GAME_CHECKMATE ||
                        status == GAME_STALEMATE) {

                        game_over = true;
                    }
                }
            }
        }



        SDL_SetRenderDrawColor(
            renderer,
            0xFF,
            0xFF,
            0xFF,
            0xFF
        );

        SDL_RenderClear(renderer);

        draw_chess_board(
            chess_game,
            renderer
        );

        draw_selection_highlight(
            renderer,
            piece_selected,
            selected_x,
            selected_y
        );

        SDL_RenderPresent(renderer);
    }



    free(chess_game);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}