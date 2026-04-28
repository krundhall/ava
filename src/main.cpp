#include "camera.h"
#include "constants.h"
#include "player.h"
#include "rendering.h"
#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Player player;
    GameCamera camera = camera_create(player.position, 35.0f, CAMERA_DISTANCE);


    while (!WindowShouldClose())
    {
        // Update
        float dt = GetFrameTime();

        camera_update(&camera, player.position, &player.facing);
        player_update(&player, dt);


        // Draw
        draw(&camera, &player);
    }
    CloseWindow();
    return 0;
}
