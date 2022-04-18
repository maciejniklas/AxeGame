#include "raylib.h"

int main()
{
    // Game constants
    const int windowWidth{350};
    const int windowHeight{200};
    const char *windowTitle{"Axe Game"};
    const float radius{25};
    const float speed(10);

    // Game variables
    int circlePositionX{windowWidth / 2};
    int circlePositionY{windowHeight / 2};

    // Initil statements
    InitWindow(windowWidth, windowHeight, windowTitle);
    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Circle horizontal movement
        if (IsKeyDown(KEY_D))
        {
            circlePositionX += speed;
        }
        else if (IsKeyDown(KEY_A))
        {
            circlePositionX -= speed;
        }

        // Circle vertical movement
        if (IsKeyDown(KEY_W))
        {
            circlePositionY -= speed;
        }
        else if (IsKeyDown(KEY_S))
        {
            circlePositionY += speed;
        }

        DrawCircle(circlePositionX, circlePositionY, radius, GREEN);

        EndDrawing();
    }
}