#include "camera.h"
#include "constants.h"
#include "object.h"
#include "player.h"
#include "rendering.h"
#include <algorithm>
#include <raylib.h>

void check_collision(Player* player, const Box* platform);

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Player player;
    GameCamera camera = camera_create(player.position, 35.0f, CAMERA_DISTANCE);
    Box platform = {{0.0f, 3.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE};

    while (!WindowShouldClose())
    {
        // Update
        float dt = GetFrameTime();

        camera_update(&camera, player.position, &player.facing);
        player_update(&player, dt);
        check_collision(&player, &platform);


        // Draw
        draw(&camera, &player, &platform);
    }
    CloseWindow();
    return 0;
}

void check_collision(Player* player, const Box* platform)
{
    BoundingBox player_box = make_bounding_box(player->position, player->size);
    BoundingBox platform_box = make_bounding_box(platform->position, platform->size);

    if (!CheckCollisionBoxes(player_box, platform_box))
        return;

    float x_overlap = std::min(player_box.max.x, platform_box.max.x) -
                      std::max(player_box.min.x, platform_box.min.x);
    float y_overlap = std::min(player_box.max.y, platform_box.max.y) -
                      std::max(player_box.min.y, platform_box.min.y);
    float z_overlap = std::min(player_box.max.z, platform_box.max.z) -
                      std::max(player_box.min.z, platform_box.min.z);

    if (y_overlap < x_overlap && y_overlap < z_overlap)
    {
        float dir = (player->position.y > platform->position.y) ? 1.0f : -1.0f;
        player->position.y += y_overlap * dir;
        player->velocity_y = 0.0f;
        player->jumps_remaining = MAX_YUMP;
    }
    else if (x_overlap < z_overlap)
    {
        float dir = (player->position.x > platform->position.x) ? 1.0f : -1.0f;
        player->position.x += x_overlap * dir;
    }
    else
    {
        float dir = (player->position.z > platform->position.z) ? 1.0f : -1.0f;
        player->position.z += z_overlap * dir;
    }
}
