#include "common.h"


void* check_if_null(void* ptr, const char* err) {
    if (ptr == NULL) {
        CHESS_ERR_LOG(err);
        exit(-1);
    }

    return ptr;
}