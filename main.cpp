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
    Color gridHoverColor = {220, 220, 220, 255};
    Color gridClickedColor = {50, 50, 50, 255};

    Rectangle grid[9];
    bool canHover[9] = {true, true, true, true, true, true, true, true, true};
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
        // Creating mouse hover effect over gridf Rects
        Vector2 mousePosition = GetMousePosition();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(screenWidth - 400, 0, screenWidth - 400, screenHeight, BLACK);

            // Draw grid
            for (int i = 0; i < 9; i++) {
                // Change grid colour based on hover bool
                if (CheckCollisionPointRec(mousePosition, grid[i]) && canHover[i] == true) {
                    DrawRectangleRec(grid[i], gridHoverColor);
                }
                else if (canHover[i] == false) {
                    DrawRectangleRec(grid[i], gridClickedColor);
                }

                // Check for mouse pressed on grid
                if (CheckCollisionPointRec(mousePosition, grid[i]) && IsMouseButtonPressed(0)) {
                    canHover[i] = false;
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

