#include "constants.h"
#include "player.h"
#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Player player;

    Camera3D camera = {
        {player.position.x, player.position.y + 10.0f, player.position.z + 10.0f}, // position
        {player.position},                                                         // target
        {0.0f, 1.0f, 0.0f},                                                        // up
        45.0f,                                                                     // fovy
        CAMERA_PERSPECTIVE                                                         // projection
    };


    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        // Update

        camera.position = {player.position.x, player.position.y + 10.0f, player.position.z + 10.0f};
        camera.target = player.position;

        // Draw
        BeginDrawing();
        ClearBackground(GRAY);

        BeginMode3D(camera);
        DrawCube(player.position, 2.0f, 2.0f, 2.0f, RED);
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
