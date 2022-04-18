#include "raylib.h"

int main()
{
    const int windowWidth{350};
    const int windowHeight{200};
    const char *windowTitle{"Axe Game"};

    InitWindow(windowWidth, windowHeight, windowTitle);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        float radius{25};
        DrawCircle(windowWidth / 2, windowHeight / 2, radius, GREEN);

        EndDrawing();
    }
}