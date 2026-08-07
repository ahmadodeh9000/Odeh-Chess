#ifndef COMMON_H
#define COMMON_H

/*  headers  */
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


/* constants */
#define CHESS_NAME          "Ahmad Chess"
#define CHESS_GAME_WIDTH    400
#define CHESS_GAME_HEIGHT   400


/* helper functions */
#define CHESS_LOG(msg)          fprintf(stdout,"LOG:%s\n",msg)
#define CHESS_ERR_LOG(err_msg)  fprintf(stdout,"ERROR:%s\n",err_msg)

void* check_if_null(void* ptr, const char* err);



#endif