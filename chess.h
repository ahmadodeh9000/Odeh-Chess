#ifndef CHESS_H
#define CHESS_H

#include "common.h"

/*
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*
*
*    k q p h r p -> white (lowercase)
*    K Q P H R P -> black (uppercase)
*/

typedef enum {
    GAME_ONGOING = 0,
    GAME_CHECKMATE,
    GAME_STALEMATE,
    GAME_CHECK /* not a terminal state, just informational */
} game_status_t;

typedef struct {
    char board[8][8];

    /* castling rights: true while the piece hasn't moved yet */
    bool white_king_moved;
    bool black_king_moved;
    bool white_rook_a_moved; /* queenside */
    bool white_rook_h_moved; /* kingside  */
    bool black_rook_a_moved;
    bool black_rook_h_moved;

    /* en passant target square set by the previous double pawn push,
     * (-1,-1) if none is available this turn */
    int en_passant_x;
    int en_passant_y;
} chess_t;



chess_t* init_chess_board(void);

/* chess logic */

bool try_move_piece(chess_t* ch, int xi, int yi, int xf, int yf, bool white_turn);
bool has_no_legal_moves(chess_t* ch, bool white_turn);
bool is_in_check(chess_t* ch, bool white);
game_status_t get_game_status(chess_t* ch, bool white_turn);


/* drawing and helpers functions */
void draw_chess_board(chess_t* ch, SDL_Renderer* renderer);
void print_chess_board_on_console(chess_t* ch);
void clear_console(void);


/* UI States and drawing */
typedef enum {
    APP_STATE_MENU = 0,
    APP_STATE_PLAY,
    APP_STATE_PAUSE,
    APP_STATE_GAMEOVER
} app_state_t;

void draw_text(const char* text, int x, int y, int scale, SDL_Renderer* renderer);
void draw_ui_overlay(app_state_t state, game_status_t game_status, bool white_turn, SDL_Renderer* renderer);

#endif