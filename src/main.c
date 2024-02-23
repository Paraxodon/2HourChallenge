#include "raylib.h"
#include "raymath.h"
#include "second.h"
#include <stdio.h>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    Vector2 initialPos = {screenWidth/2, screenHeight/2};

    InitWindow(screenWidth, screenHeight, "Game");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircle(initialPos.x, initialPos.y, 15, RED);

            DrawFPS(0,0);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
