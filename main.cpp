#include "raylib.h"

int main()
{
    // Game constants
    const int windowWidth{800};
    const int windowHeight{450};
    const char *windowTitle{"Axe Game"};
    const int radius{25};

    // Game variables
    int speed{10};
    int circlePositionX{windowWidth / 4};
    int circlePositionY{windowHeight / 4};
    int axePositionX{windowWidth / 2};
    int axePositionY{windowHeight / 2};
    int axeDirectionY{1};
    bool collisionWithAxe{false};

    // Edges of the circle
    int circleLeftEdge{circlePositionX - radius};
    int circleRightEdge{circlePositionX + radius};
    int circleTopEdge{circlePositionY - radius};
    int circleBottomEdge{circlePositionY + radius};

    // Edges of the axe
    int axeLeftEdge{axePositionX - radius};
    int axeRightEdge{axePositionX + radius};
    int axeTopEdge{axePositionY - radius};
    int axeBottomEdge{axePositionY + radius};

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

        // Axe movement
        axePositionY += axeDirectionY * speed;

        if (axePositionY > windowHeight || axePositionY < 0)
        {
            axeDirectionY *= -1;
        }

        DrawRectangle(axePositionX - radius, axePositionY - radius, radius * 2, radius * 2, RED);

        // Detecting collision with axe

        // Edges of the circle
        circleLeftEdge = circlePositionX - radius;
        circleRightEdge = circlePositionX + radius;
        circleTopEdge = circlePositionY - radius;
        circleBottomEdge = circlePositionY + radius;

        // Edges of the axe
        axeLeftEdge = axePositionX - radius;
        axeRightEdge = axePositionX + radius;
        axeTopEdge = axePositionY - radius;
        axeBottomEdge = axePositionY + radius;

        // Collision flag
        collisionWithAxe = axeBottomEdge >= circleTopEdge && axeTopEdge <= circleBottomEdge && axeLeftEdge <= circleRightEdge && axeRightEdge >= circleLeftEdge;

        if (collisionWithAxe)
        {
            speed = 0;
            DrawText("Game over!", 25, 25, 50, RED);
        }

        EndDrawing();
    }
}