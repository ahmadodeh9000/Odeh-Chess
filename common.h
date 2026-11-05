#ifndef COMMON_H
#define COMMON_H

/*  headers  */

// checks if SDL2 is installed inside the system !
#if defined(__has_include)
	#if __has_include(<SDL2/SDL.h>)
		#include <SDL2/SDL.h>	
		#define SDL_AVAILABLE 1
	#elif __has_include(<SDL.h>)
		#include <SDL.h>	
		#define SDL_AVAILABLE 1
	#else 	
		#define SDL_AVAILABLE 0
	#endif
#else
	#define SDL_AVAILABLE 0
#endif

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