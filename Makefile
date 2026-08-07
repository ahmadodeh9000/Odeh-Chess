# ============================================================
# Makefile for chess (SDL2, C)
# Author: Ahmad Odeh
# ============================================================

# --- Project layout ---------------------------------------
SRC_DIR   := .
OBJ_DIR   := build/obj
BIN_DIR   := build/bin
TARGET    := $(BIN_DIR)/chess

SRCS      := $(wildcard $(SRC_DIR)/*.c)
OBJS      := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS      := $(OBJS:.o=.d)

# --- Compiler ------------------------------------------------
CC        := cc
CSTD      := -std=c11

# --- SDL2 flags (works on Linux via pkg-config, macOS via sdl2-config) ---
SDL2_CFLAGS := $(shell pkg-config --cflags sdl2 2>/dev/null || sdl2-config --cflags)
SDL2_LIBS   := $(shell pkg-config --libs sdl2 2>/dev/null || sdl2-config --libs)

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
	mkdir -p $@

run: all
	./$(TARGET)

rebuild: clean all

clean:
	rm -rf build

-include $(DEPS)