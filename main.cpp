#include <iostream>
#include <raylib.h>

int main() {
    const int screenWidth = 700;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "TicTacToe");
    SetTargetFPS(60);

    // Set grid
    float gridWidth = 130.0f;
    float gridHeight = 130.0f;
    Color gridRectColor = {210, 210, 210, 255};
    Rectangle grid[9];
        // Row 1
    grid[0] = {screenWidth - 400, 0, gridWidth, gridHeight};
    grid[1] = {screenWidth - 265, 0, gridWidth, gridHeight};
    grid[2] = {screenWidth - gridWidth, 0, gridWidth, gridHeight};
        // Row 2
    grid[3] = {screenWidth - 400, gridHeight + 5, gridWidth, gridHeight};
    grid[4] = {screenWidth - 265, gridHeight + 5, gridWidth, gridHeight};
    grid[5] = {screenWidth - gridWidth, gridHeight + 5, gridWidth, gridHeight};
        // Row 3
    grid[6] = {screenWidth - 400, screenHeight - gridHeight, gridWidth, gridHeight};
    grid[7] = {screenWidth - 265, screenHeight - gridHeight, gridWidth, gridHeight};
    grid[8] = {screenWidth - gridWidth, screenHeight - gridHeight, gridWidth, gridHeight};

    while(!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(screenWidth - 400, 0, screenWidth - 400, screenHeight, BLACK);

            // Draw grid
            for (int i = 0; i < sizeof(grid); i++) {
                DrawRectangleRec(grid[i], gridRectColor);
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

