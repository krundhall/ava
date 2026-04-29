#include "constants.h"
#include <raylib.h>
// hello chat
int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    Vector2 monitor_pos = GetMonitorPosition(0);
    SetWindowPosition((int)monitor_pos.x + (GetMonitorWidth(0) - SCREEN_WIDTH) / 2,
                      (int)monitor_pos.y + (GetMonitorHeight(0) - SCREEN_HEIGHT) / 2);
    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        // Update
        BeginDrawing();
        ClearBackground(GRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
