#include "ball.h"
#include "camera.h"
#include "collision.h"
#include "constants.h"
#include "object.h"
#include "player.h"
#include "rendering.h"
#include "world.h"
#include <raylib.h>
// hello chat
int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Player player;
    Ball ball = {{0.0f, 5.0f, 15.0f}, 2.0f, RAYWHITE, 5.0f, 5.0f, 5.0f};
    GameCamera camera = camera_create(player.position, 35.0f, CAMERA_DISTANCE);
    std::vector<Box> platform_vector = build_platform_vector();

    while (!WindowShouldClose())
    {
        // Update
        float dt = GetFrameTime();

        camera_update(&camera, player.position, &player.facing);
        player_update(&player, dt);
        ball_update(&ball, dt);
        run_collisions(&player, &ball, platform_vector);
        // Draw
        draw(&camera, &player, platform_vector, ball);
    }
    CloseWindow();
    return 0;
}
