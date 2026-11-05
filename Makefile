# ============================================================
# Makefile for chess (SDL2, C)
# Author: Ahmad Odeh
# ============================================================

# --- Project layout ---------------------------------------
SRC_DIR   := .
OBJ_DIR   := build/obj
BIN_DIR   := build/bin
TARGET_NAME := chess
ifeq ($(OS),Windows_NT)
    TARGET    := $(BIN_DIR)/$(TARGET_NAME).exe
    CC        := gcc
else
    TARGET    := $(BIN_DIR)/$(TARGET_NAME)
    CC        := cc
endif

SRCS      := $(wildcard $(SRC_DIR)/*.c)
OBJS      := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS      := $(OBJS:.o=.d)

# --- Compiler ------------------------------------------------
CSTD      := -std=c11

# --- SDL2 flags (works on Linux via pkg-config, macOS via sdl2-config) ---
ifeq ($(OS),Windows_NT)
    # Check for local include/lib folders first, otherwise try pkg-config
    ifneq ($(wildcard ./include/SDL2/SDL.h),)
        SDL2_CFLAGS := -I./include
        SDL2_LIBS   := -L./lib -lmingw32 -lSDL2main -lSDL2
    else
        SDL2_CFLAGS := $(shell pkg-config --cflags sdl2 2>nul)
        SDL2_LIBS   := $(shell pkg-config --libs sdl2 2>nul)
        ifeq ($(SDL2_LIBS),)
            SDL2_LIBS := -lmingw32 -lSDL2main -lSDL2
        endif
    endif
else
    SDL2_CFLAGS := $(shell pkg-config --cflags sdl2 2>/dev/null || sdl2-config --cflags)
    SDL2_LIBS   := $(shell pkg-config --libs sdl2 2>/dev/null || sdl2-config --libs)
endif

# --- Warnings / flags ----------------------------------------
WARN      := -Wall -Wextra -Wpedantic
INCLUDES  := -I$(SRC_DIR) $(SDL2_CFLAGS)
LIBS      := $(SDL2_LIBS) -lm

CFLAGS    := $(CSTD) $(WARN) $(INCLUDES) -MMD -MP
LDFLAGS   := $(LIBS)

BUILD ?= release

ifeq ($(BUILD),debug)
    CFLAGS += -g -O0 -DDEBUG -fsanitize=address,undefined
    LDFLAGS += -fsanitize=address,undefined
else
    CFLAGS += -O2 -DNDEBUG
endif

.PHONY: all debug clean run rebuild

all: $(TARGET)

debug:
	$(MAKE) BUILD=debug

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	@echo "Built $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
ifeq ($(OS),Windows_NT)
	if not exist "$(subst /,\,$@)" mkdir "$(subst /,\,$@)"
else
	mkdir -p $@
endif

run: all
ifeq ($(OS),Windows_NT)
	$(subst /,\,$(TARGET))
else
	./$(TARGET)
endif

rebuild: clean all

clean:
ifeq ($(OS),Windows_NT)
	if exist build rmdir /S /Q build
else
	rm -rf build
endif

-include $(DEPS)