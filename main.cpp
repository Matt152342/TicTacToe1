#include <cstdlib>
#include <ctime>
#include <iostream>
#include <raylib.h>

int main() {
    const int screenWidth = 700;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "TicTacToe");
    SetTargetFPS(60);

    std::srand(std::time(0));

    bool playerTurn = true;
    int playerMove = 0;

    // grid attributes
    float gridWidth = 130.0f;
    float gridHeight = 130.0f;
    Color gridHoverColor = {220, 220, 220, 255};
    Color playerColor = {80, 180, 80, 255};

    Rectangle grid[9];
    int board[9] = {0, 0, 0,
                    0, 0, 0,
                    0, 0, 0}; // 0 = empty, 1 = player, 2 = enemy

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

        // Checks if it's player's turn or not
        if (playerTurn) {
            DrawText("Player turn", 0, 0, 30, BLACK);
        }
        else {
            DrawText("Bot's turn", 0, 0, 30, BLACK);
        }

        // AI logic
        for (int i = 0; i < 9; i++) {
            // Take center if free
            if (playerMove == 1 && !playerTurn) {
                if (board[4] != 1) {
                    board[4] = 2;
                    playerTurn = true;
                }
                else {
                    int randomBlock = rand() % 10;
                    if (board[randomBlock] != 1) {
                        board[randomBlock] = 2;
                        playerTurn = true;
                    }
                }
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(screenWidth - 400, 0, screenWidth - 400, screenHeight, BLACK);
            
            // Grid
            for (int i = 0; i < 9; i++) {
                // Change grid colour based on hover
                if (CheckCollisionPointRec(mousePosition, grid[i]) && board[i] == 0) {
                    DrawRectangleRec(grid[i], gridHoverColor);
                }

                // Change grid colours based on block state
                else if (board[i] == 1) {
                    DrawRectangleRec(grid[i], playerColor);
                }
                else if (board[i] == 2) {
                    DrawRectangleRec(grid[i], RED);
                }

                // Check for mouse pressed on grid
                if (CheckCollisionPointRec(mousePosition, grid[i]) && IsMouseButtonPressed(0) && playerTurn == true) {
                    board[i] = 1;
                    playerMove++;
                    playerTurn = false;
                }
            }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

