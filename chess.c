#include "chess.h"
#include "common.h"


/*==============================================
============DRAWING CHESS PIECES================
===============================================*/

/*
*    R H B Q K B H R 
*    P P P P P P P P 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    # # # # # # # # 
*    p p p p p p p p 
*    r h b q k b h r 
*
*
*    k q p h r p -> white
*    K Q P H R P -> black
*/

static const char* rock_piece[] = {
    "         ",
    "         ",
    "         ",
    " # # # # ",
    " # # # # ",
    " # # # # ",
    " # # # # ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    " ####### ",
    " ####### ",
    " ####### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
};

static const char* bishop_piece[] = {
    "    #    ",
    "   # #   ",
    "  ###    ",
    " #####   ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
    "#########",
};

static const char* king_piece[] = {
    "    #    ",
    "    #    ",
    "    #    ",
    "  #####  ",
    "    #    ",
    "    #    ",
    "    #    ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    " ####### ",
    " ####### ",
    " ####### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
};

static const char* queen_piece[] = {
    " # # # # ",
    "  # # #  ",
    " # # # # ",
    "#########",
    "#########",
    "#########",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    "  #####  ",
    " ####### ",
    " ####### ",
    " ####### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
};

static const char* knight_piece[] = {
    "         ",
    "         ",
    "         ",
    "         ",
    "     ### ",
    "   ##### ",
    " ########",
    "#########",
    "  #######",
    "    #####",
    "   ##### ",
    "  ###### ",
    "  ###### ",
    "  ###### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "#########",
};

static const char* pawn_piece[] = {
    "         ",
    "         ",
    "         ",
    "         ",
    "         ",
    "         ",
    "   ###   ",
    " ####### ",
    "#########",
    "#########",
    "#########",
    "  #####  ",
    "  #####  ",
    " ####### ",
    " ####### ",
    " ####### ",
    "#########",
    "#########",
    "#########",
};

static void draw_piece(const char* piece[], int posx, int posy,SDL_Renderer* renderer) {

    int peice_tile = 2;

    for (int i = 0; i < 18; ++i) {
        for (int j = 0 ; j < 9; ++j) {
            if (piece[i][j] == '#') {
                SDL_Rect rect = {posx + j * peice_tile , posy + i * peice_tile, 3, 3};
                SDL_RenderFillRect(renderer,&rect);
            }

            
        }
    }
}

static void draw_pieces(chess_t* ch, SDL_Renderer* renderer) {

    int tile = CHESS_GAME_WIDTH / 8;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            
            if (isupper((unsigned char)ch->board[i][j])) {
                SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0XFF);

                if (ch->board[i][j] == 'R') {
                    draw_piece(rock_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'B') {
                    draw_piece(bishop_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'P') {
                    draw_piece(pawn_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'K') {
                    draw_piece(king_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'Q') {
                    draw_piece(queen_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'H') {
                    draw_piece(knight_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }

            }

            else if (islower((unsigned char)ch->board[i][j])) {
                SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0XFF);

                if (ch->board[i][j] == 'r') {
                    draw_piece(rock_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'b') {
                    draw_piece(bishop_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'p') {
                    draw_piece(pawn_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'k') {
                    draw_piece(king_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'q') {
                    draw_piece(queen_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                if (ch->board[i][j] == 'h') {
                    draw_piece(knight_piece,(j * tile) + (tile / 4), (i * tile)+ (tile / 4),renderer);
                    continue;
                }
                
            }

            else continue;

            SDL_Rect rect = {(j * tile) + (tile / 4), i * tile + (tile / 4), tile / 2, tile / 2};


            SDL_RenderFillRect(renderer,&rect);
        }

    }
}


chess_t* init_chess_board(void) {
    chess_t* ch = (chess_t*) malloc(sizeof(chess_t));

    const char* rows[8] = {
        "RHBQKBHR",
        "PPPPPPPP",
        "        ",
        "        ",
        "        ",
        "        ",
        "pppppppp",
        "rhbqkbhr"
    };
    

    for (int i = 0; i < 8 ; ++i) {
        for (int j = 0; j < 8; ++j) {
            ch->board[i][j] = rows[i][j];
        }
    }

    ch->white_king_moved = false;
    ch->black_king_moved = false;
    ch->white_rook_a_moved = false;
    ch->white_rook_h_moved = false;
    ch->black_rook_a_moved = false;
    ch->black_rook_h_moved = false;
    ch->en_passant_x = -1;
    ch->en_passant_y = -1;

    return ch;

}

void print_chess_board_on_console(chess_t* ch) {

    if (NULL == ch) {
        CHESS_ERR_LOG("BOARD IS NULL");
        exit(-67);
    }

    for (int8_t i = 0; i < 8; ++i) {
        for (int8_t j = 0; j < 8; ++j) {
            printf("%c",ch->board[i][j]);
        }
        printf("\n");
    }
    
}
void clear_console(void) {
    printf("\033[H\033[2J");
}

void draw_chess_board(chess_t* ch,SDL_Renderer* renderer) {


    int tile = CHESS_GAME_WIDTH / 8;

    /* draws the board */

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!((i + j) % 2)) SDL_SetRenderDrawColor(renderer,0xE6,0xD2,0xAE,0XFF);
            else SDL_SetRenderDrawColor(renderer,0x30,0x2E,0x26,0xFF);

            SDL_Rect rect = {j * tile, i * tile, tile , tile};
            SDL_RenderFillRect(renderer,&rect);
        }
    }

    /* draws the pieces */
    draw_pieces(ch,renderer);
    
        
}




/*===================================================
==================CHESS LOGIC======================
====================================================*/

/* board convention: lowercase = white, uppercase = black, ' ' = empty
 * (kept identical to the original code's convention) */

static bool on_board(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

static bool is_white_piece(char c) {
    return c != ' ' && islower((unsigned char)c);
}

static bool is_black_piece(char c) {
    return c != ' ' && isupper((unsigned char)c);
}

static bool is_own_piece(char c, bool white) {
    return white ? is_white_piece(c) : is_black_piece(c);
}

static bool is_enemy_piece(char c, bool white) {
    return white ? is_black_piece(c) : is_white_piece(c);
}

/* true if every square strictly between (xi,yi) and (xf,yf) is empty.
 * Only valid to call for straight or diagonal lines. */
static bool is_path_clear(chess_t* ch, int xi, int yi, int xf, int yf) {
    int dx = (xf > xi) - (xf < xi);
    int dy = (yf > yi) - (yf < yi);

    int x = xi + dx;
    int y = yi + dy;

    while (x != xf || y != yf) {
        if (ch->board[y][x] != ' ') return false;
        x += dx;
        y += dy;
    }
    return true;
}

/* Pure geometric/piece-movement legality: ignores checks, but DOES account
 * for en-passant and treats castling as a king "jumping" 2 squares (the
 * actual rook hop + right checks are handled separately in try_move_piece). */
static bool piece_move_shape_ok(chess_t* ch, int xi, int yi, int xf, int yf, bool white) {
    char piece = ch->board[yi][xi];
    char target = ch->board[yf][xf];
    char p = tolower((unsigned char)piece);

    int dx = xf - xi;
    int dy = yf - yi;
    int adx = abs(dx);
    int ady = abs(dy);

    if (is_own_piece(target, white)) return false;

    switch (p) {
        case 'p': {
            int dir = white ? -1 : 1;       /* white moves up the array (row 0 = black back rank) */
            int start_row = white ? 6 : 1;

            /* forward move (no capture) */
            if (dx == 0 && target == ' ') {
                if (dy == dir) return true;
                if (yi == start_row && dy == 2 * dir &&
                    ch->board[yi + dir][xi] == ' ') return true;
                return false;
            }
            /* diagonal capture */
            if (adx == 1 && dy == dir) {
                if (is_enemy_piece(target, white)) return true;
                /* en passant */
                if (target == ' ' && ch->en_passant_x == xf && ch->en_passant_y == yf) return true;
            }
            return false;
        }
        case 'h': /* knight */
            return (adx == 1 && ady == 2) || (adx == 2 && ady == 1);

        case 'b': /* bishop */
            return adx == ady && adx != 0 && is_path_clear(ch, xi, yi, xf, yf);

        case 'r': /* rook */
            return ((dx == 0) != (dy == 0)) && is_path_clear(ch, xi, yi, xf, yf);

        case 'q': /* queen */
            if (adx == ady && adx != 0) return is_path_clear(ch, xi, yi, xf, yf);
            if ((dx == 0) != (dy == 0)) return is_path_clear(ch, xi, yi, xf, yf);
            return false;

        case 'k': { /* king, castling shape allowed here, legality checked by caller */
            if (adx <= 1 && ady <= 1) return true;
            if (ady == 0 && adx == 2) return true; /* castle attempt */
            return false;
        }
        default:
            return false;
    }
}

/* true if the square (x,y) is attacked by the side `by_white` */
static bool is_square_attacked(chess_t* ch, int x, int y, bool by_white) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c = ch->board[i][j];
            if (c == ' ') continue;
            if (by_white && !is_white_piece(c)) continue;
            if (!by_white && !is_black_piece(c)) continue;

            char p = tolower((unsigned char)c);
            int dx = x - j;
            int dy = y - i;
            int adx = abs(dx);
            int ady = abs(dy);

            if (p == 'p') {
                int dir = by_white ? -1 : 1;
                if (adx == 1 && dy == dir) return true;
            } else if (p == 'h') {
                if ((adx == 1 && ady == 2) || (adx == 2 && ady == 1)) return true;
            } else if (p == 'k') {
                if (adx <= 1 && ady <= 1 && (adx || ady)) return true;
            } else if (p == 'b') {
                if (adx == ady && adx != 0 && is_path_clear(ch, j, i, x, y)) return true;
            } else if (p == 'r') {
                if (((dx == 0) != (dy == 0)) && is_path_clear(ch, j, i, x, y)) return true;
            } else if (p == 'q') {
                if (((adx == ady && adx != 0) || (dx == 0) != (dy == 0)) &&
                    is_path_clear(ch, j, i, x, y)) return true;
            }
        }
    }
    return false;
}

static void find_king(chess_t* ch, bool white, int* kx, int* ky) {
    char target = white ? 'k' : 'K';
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (ch->board[i][j] == target) { *kx = j; *ky = i; return; }
    *kx = -1; *ky = -1;
}

bool is_in_check(chess_t* ch, bool white) {
    int kx, ky;
    find_king(ch, white, &kx, &ky);
    if (kx == -1) return false; /* no king on board, shouldn't happen */
    return is_square_attacked(ch, kx, ky, !white);
}

/* Applies a move with no legality checking, handling en-passant capture and
 * castling rook hop. Returns the captured piece char if any (for undo) via
 * out params isn't needed here since callers only use this on copies. */
static void apply_move_raw(chess_t* ch, int xi, int yi, int xf, int yf) {
    char piece = ch->board[yi][xi];
    char p = tolower((unsigned char)piece);

    /* en passant capture: pawn moves diagonally into an empty square that
     * matches the stored en-passant target -> remove the captured pawn */
    if (p == 'p' && xf != xi && ch->board[yf][xf] == ' ' &&
        ch->en_passant_x == xf && ch->en_passant_y == yf) {
        ch->board[yi][xf] = ' '; /* captured pawn sits on the origin row, target column */
    }

    /* castling: king moves two squares horizontally -> hop the rook too */
    if (p == 'k' && abs(xf - xi) == 2) {
        int row = yi;
        if (xf > xi) { /* kingside */
            ch->board[row][xf - 1] = ch->board[row][7];
            ch->board[row][7] = ' ';
        } else { /* queenside */
            ch->board[row][xf + 1] = ch->board[row][0];
            ch->board[row][0] = ' ';
        }
    }

    ch->board[yf][xf] = piece;
    ch->board[yi][xi] = ' ';

    /* auto-promote pawns that reach the last rank, always to a queen */
    if (p == 'p' && (yf == 0 || yf == 7)) {
        ch->board[yf][xf] = isupper((unsigned char)piece) ? 'Q' : 'q';
    }
}

/* full legality check: shape + castling rights/attacked-squares + doesn't
 * leave your own king in check */
static bool is_legal_move(chess_t* ch, int xi, int yi, int xf, int yf, bool white) {
    if (!on_board(xi, yi) || !on_board(xf, yf)) return false;
    if (xi == xf && yi == yf) return false;

    char piece = ch->board[yi][xi];
    if (piece == ' ') return false;
    if (!is_own_piece(piece, white)) return false;

    if (!piece_move_shape_ok(ch, xi, yi, xf, yf, white)) return false;

    /* extra castling-specific validation */
    char p = tolower((unsigned char)piece);
    if (p == 'k' && abs(xf - xi) == 2) {
        bool kingside = xf > xi;
        int row = yi;

        bool king_moved  = white ? ch->white_king_moved  : ch->black_king_moved;
        bool rook_moved   = kingside ?
            (white ? ch->white_rook_h_moved : ch->black_rook_h_moved) :
            (white ? ch->white_rook_a_moved : ch->black_rook_a_moved);

        if (king_moved || rook_moved) return false;
        if (is_in_check(ch, white)) return false; /* can't castle out of check */

        int rook_col = kingside ? 7 : 0;
        char rook_char = white ? 'r' : 'R';
        if (ch->board[row][rook_col] != rook_char) return false;

        if (!is_path_clear(ch, xi, yi, rook_col, row)) return false;

        int step = kingside ? 1 : -1;
        /* king can't pass through or land on an attacked square */
        if (is_square_attacked(ch, xi + step, row, !white)) return false;
        if (is_square_attacked(ch, xi + 2 * step, row, !white)) return false;
    }

    /* simulate the move on a scratch copy and reject it if it leaves our
     * own king in check */
    chess_t copy = *ch;
    apply_move_raw(&copy, xi, yi, xf, yf);
    if (is_in_check(&copy, white)) return false;

    return true;
}

bool has_no_legal_moves(chess_t* ch, bool white) {
    for (int yi = 0; yi < 8; ++yi) {
        for (int xi = 0; xi < 8; ++xi) {
            if (!is_own_piece(ch->board[yi][xi], white)) continue;
            for (int yf = 0; yf < 8; ++yf) {
                for (int xf = 0; xf < 8; ++xf) {
                    if (is_legal_move(ch, xi, yi, xf, yf, white)) return false;
                }
            }
        }
    }
    return true;
}

game_status_t get_game_status(chess_t* ch, bool white_turn) {
    bool no_moves = has_no_legal_moves(ch, white_turn);
    bool in_check = is_in_check(ch, white_turn);

    if (no_moves) return in_check ? GAME_CHECKMATE : GAME_STALEMATE;
    if (in_check) return GAME_CHECK;
    return GAME_ONGOING;
}

bool try_move_piece(chess_t* ch, int xi, int yi, int xf, int yf, bool white_turn) {
    if (!is_legal_move(ch, xi, yi, xf, yf, white_turn)) return false;

    char piece = ch->board[yi][xi];
    char p = tolower((unsigned char)piece);

    /* update castling rights before mutating the board */
    if (p == 'k') {
        if (white_turn) ch->white_king_moved = true; else ch->black_king_moved = true;
    }
    if (p == 'r') {
        if (white_turn) {
            if (xi == 0 && yi == 7) ch->white_rook_a_moved = true;
            if (xi == 7 && yi == 7) ch->white_rook_h_moved = true;
        } else {
            if (xi == 0 && yi == 0) ch->black_rook_a_moved = true;
            if (xi == 7 && yi == 0) ch->black_rook_h_moved = true;
        }
    }
    /* if a rook gets captured on its home square, it can no longer castle */
    if (xf == 0 && yf == 7) ch->white_rook_a_moved = true;
    if (xf == 7 && yf == 7) ch->white_rook_h_moved = true;
    if (xf == 0 && yf == 0) ch->black_rook_a_moved = true;
    if (xf == 7 && yf == 0) ch->black_rook_h_moved = true;

    apply_move_raw(ch, xi, yi, xf, yf);

    /* set / clear the en-passant target for the *next* move only */
    if (p == 'p' && abs(yf - yi) == 2) {
        ch->en_passant_x = xf;
        ch->en_passant_y = (yi + yf) / 2;
    } else {
        ch->en_passant_x = -1;
        ch->en_passant_y = -1;
    }

    return true;
}

/*===================================================
==================UI RENDERING=====================
====================================================*/

static const char* font_5x5[26][5] = {
    {" ### ", "#   #", "#####", "#   #", "#   #"}, /* A */
    {"#### ", "#   #", "#### ", "#   #", "#### "}, /* B */
    {" ####", "#    ", "#    ", "#    ", " ####"}, /* C */
    {"#### ", "#   #", "#   #", "#   #", "#### "}, /* D */
    {"#####", "#    ", "#### ", "#    ", "#####"}, /* E */
    {"#####", "#    ", "#### ", "#    ", "#    "}, /* F */
    {" ####", "#    ", "# ###", "#   #", " ####"}, /* G */
    {"#   #", "#   #", "#####", "#   #", "#   #"}, /* H */
    {" ### ", "  #  ", "  #  ", "  #  ", " ### "}, /* I */
    {"    #", "    #", "    #", "#   #", " ### "}, /* J */
    {"#   #", "#  # ", "###  ", "#  # ", "#   #"}, /* K */
    {"#    ", "#    ", "#    ", "#    ", "#####"}, /* L */
    {"#   #", "## ##", "# # #", "#   #", "#   #"}, /* M */
    {"#   #", "##  #", "# # #", "#  ##", "#   #"}, /* N */
    {" ### ", "#   #", "#   #", "#   #", " ### "}, /* O */
    {"#### ", "#   #", "#### ", "#    ", "#    "}, /* P */
    {" ### ", "#   #", "#   #", "#  ##", " ####"}, /* Q */
    {"#### ", "#   #", "#### ", "#  # ", "#   #"}, /* R */
    {" ####", "#    ", " ### ", "    #", "#### "}, /* S */
    {"#####", "  #  ", "  #  ", "  #  ", "  #  "}, /* T */
    {"#   #", "#   #", "#   #", "#   #", " ### "}, /* U */
    {"#   #", "#   #", "#   #", " # # ", "  #  "}, /* V */
    {"#   #", "#   #", "# # #", "## ##", "#   #"}, /* W */
    {"#   #", " # # ", "  #  ", " # # ", "#   #"}, /* X */
    {"#   #", " # # ", "  #  ", "  #  ", "  #  "}, /* Y */
    {"#####", "   # ", "  #  ", " #   ", "#####"}  /* Z */
};

static const char* font_punct_5x5[2][5] = {
    {"  #  ", "  #  ", "  #  ", "     ", "  #  "}, /* ! */
    {"     ", "     ", "     ", "     ", "     "}  /* space */
};

void draw_text(const char* text, int x, int y, int scale, SDL_Renderer* renderer) {
    int cursor_x = x;
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = toupper((unsigned char)text[i]);
        const char** glyph = NULL;
        
        if (c >= 'A' && c <= 'Z') {
            glyph = (const char**)font_5x5[c - 'A'];
        } else if (c == '!') {
            glyph = (const char**)font_punct_5x5[0];
        } else if (c == ' ') {
            glyph = (const char**)font_punct_5x5[1];
        } else {
            glyph = (const char**)font_punct_5x5[1]; /* fallback space */
        }
        
        if (glyph) {
            for (int r = 0; r < 5; ++r) {
                for (int c_idx = 0; c_idx < 5; ++c_idx) {
                    if (glyph[r][c_idx] == '#') {
                        SDL_Rect rect = {cursor_x + c_idx * scale, y + r * scale, scale, scale};
                        SDL_RenderFillRect(renderer, &rect);
                    }
                }
            }
        }
        cursor_x += 6 * scale; /* 5px width + 1px spacing */
    }
}

void draw_ui_overlay(app_state_t state, game_status_t game_status, bool white_turn, SDL_Renderer* renderer) {
    if (state == APP_STATE_PLAY && game_status != GAME_CHECK) return;

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    if (state == APP_STATE_MENU || state == APP_STATE_PAUSE || state == APP_STATE_GAMEOVER) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180);
        SDL_Rect overlay = {0, 0, CHESS_GAME_WIDTH, CHESS_GAME_HEIGHT};
        SDL_RenderFillRect(renderer, &overlay);
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    if (state == APP_STATE_MENU) {
        draw_text("AHMAD CHESS", 65, 120, 4, renderer);
        draw_text("CLICK TO START", 65, 220, 2, renderer);
    } 
    else if (state == APP_STATE_PAUSE) {
        draw_text("PAUSED", 128, 150, 4, renderer);
        draw_text("ESC TO RESUME", 95, 220, 2, renderer);
    }
    else if (state == APP_STATE_GAMEOVER) {
        if (game_status == GAME_CHECKMATE) {
            SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
            draw_text("CHECKMATE!", 80, 100, 4, renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            if (white_turn) {
                draw_text("BLACK WINS", 110, 150, 3, renderer);
            } else {
                draw_text("WHITE WINS", 110, 150, 3, renderer);
            }
        } else {
            SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
            draw_text("STALEMATE", 90, 100, 4, renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            draw_text("DRAW", 150, 150, 3, renderer);
        }
        draw_text("CLICK TO RESTART", 55, 250, 2, renderer);
    }
    else if (state == APP_STATE_PLAY && game_status == GAME_CHECK) {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        draw_text("CHECK!", 160, 10, 2, renderer);
    }
    
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
}