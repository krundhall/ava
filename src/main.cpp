#include "camera.h"
#include "constants.h"
#include "player.h"
#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Player player;
    GameCamera camera = camera_create(player.position, 45.0f, 10.0f);


    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        // Update

        camera_update(&camera, player.position, &player.facing);
        player_update(&player, dt);

        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        BeginMode3D(camera.cam3d);
        player_draw(&player);
        DrawCubeWires(player.position, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("Ava", 10, 40, 20, DARKGRAY);
        DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
