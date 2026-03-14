#include <iostream>
#include <raylib.h>

int main() {
    const int screenWidth = 600;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "TicTacToe");

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}