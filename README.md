# Odeh-Chess

A lightweight, fully-featured 2D chess game built in C using SDL2. It features custom-drawn blocky pixel-art graphics and native UI menus, without relying on any external font or image libraries (like `SDL_ttf` or `SDL_image`).

## Features
- Standard chess logic including check, checkmate, stalemate, castling, and en-passant.
- Custom rendering for chessboard and pieces using native SDL primitives.
- Built-in UI system featuring a Start Menu, Pause Menu, Check warnings, and Game Over screen using a custom 5x5 pixel-art font.
- Cross-platform `Makefile` with built-in native support for Windows.

## Controls
- **Left Mouse Click:** 
  - Select and move pieces during gameplay.
  - Start the game from the main menu.
  - Restart the game from the Game Over screen.
- **ESC Key:** 
  - Toggle the Pause menu during a match.
  - Exit the game from the pause menu or start menu.

## How to Run on Windows

1. **Prerequisites**: Ensure you have `make` and a C compiler (like `gcc` via MinGW) installed and added to your system `PATH`.
2. **Setup SDL2 Development Libraries**: We need to download the C headers (`.h` files) and library files (`.a` files) for SDL2 to compile the code.
   - Run the provided setup script from your terminal:
     ```cmd
     python setup_sdl2.py
     ```
   - This will automatically fetch the correct SDL2 release, extract it into local `include/` and `lib/` folders, and place the necessary `SDL2.dll` runtime library into your root directory so the game can run immediately after building.
3. **Compile**: 
   - Once the setup script finishes, compile the project using `make`:
     ```cmd
     make
     ```
4. **Play**: 
   - Run the generated executable:
     ```cmd
     build\bin\chess.exe
     ```

## How to Run on Linux/macOS
1. Install SDL2 development packages through your package manager (e.g., `sudo apt install libsdl2-dev` on Ubuntu, or `brew install sdl2` on macOS).
2. Run `make` in the root directory.
3. Launch the game: `./build/bin/chess`

## License
See the [LICENSE](LICENSE) file for more details.
