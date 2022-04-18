#include "raylib.h"

int main()
{
    // Game constants
    const int windowWidth{800};
    const int windowHeight{450};
    const char *windowTitle{"Axe Game"};
    const float radius{25};
    const float speed(10);

    // Game variables
    int circlePositionX{windowWidth / 2};
    int circlePositionY{windowHeight / 4};
    int axePositionX{windowWidth / 2};
    int axePositionY{windowHeight / 2};

    // Initil statements
    InitWindow(windowWidth, windowHeight, windowTitle);
    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Circle horizontal movement
        if (IsKeyDown(KEY_D) && circlePositionX < windowWidth)
        {
            circlePositionX += speed;
        }
        else if (IsKeyDown(KEY_A) && circlePositionX > 0)
        {
            circlePositionX -= speed;
        }

        // Circle vertical movement
        if (IsKeyDown(KEY_W) && circlePositionY > 0)
        {
            circlePositionY -= speed;
        }
        else if (IsKeyDown(KEY_S) && circlePositionY < windowHeight)
        {
            circlePositionY += speed;
        }

        DrawCircle(circlePositionX, circlePositionY, radius, GREEN);

        DrawRectangle(axePositionX - radius, axePositionY - radius, radius * 2, radius * 2, RED);

        EndDrawing();
    }
}