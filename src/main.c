#include "raylib.h"
#include "raymath.h"
#include "physac.h"
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
    InitPhysics();

    PhysicsBody floor = CreatePhysicsBodyRectangle((Vector2){screenWidth/2, screenHeight}, 500, 100, 10);
    floor->enabled = false;

    PhysicsBody player = CreatePhysicsBodyCircle((Vector2){screenWidth/2, screenHeight/2}, 45, 10);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawCircle(player->position.x, player->position.y, 15, RED);

            DrawFPS(0,0);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    ClosePhysics();
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
