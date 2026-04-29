#include "ball.h"
#include "camera.h"
#include "constants.h"
#include "object.h"
#include "player.h"
#include "rendering.h"
#include "world.h"
#include <algorithm>
#include <raylib.h>
void check_collision(Player* player, const std::vector<Box> &platforms);
void player_ball_collision(Player* player, Ball* ball);
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
        check_collision(&player, platform_vector);
        player_ball_collision(&player, &ball);
        // Draw
        draw(&camera, &player, platform_vector, ball);
    }
    CloseWindow();
    return 0;
}

void check_collision(Player* player, const std::vector<Box> &platforms)
{
    for (const auto &platform : platforms)
    {
        BoundingBox player_box = make_bounding_box(player->position, player->size);
        BoundingBox platform_box = make_bounding_box(platform.position, platform.size);

        if (!CheckCollisionBoxes(player_box, platform_box))
            continue;

        float x_overlap = std::min(player_box.max.x, platform_box.max.x) -
                          std::max(player_box.min.x, platform_box.min.x);
        float y_overlap = std::min(player_box.max.y, platform_box.max.y) -
                          std::max(player_box.min.y, platform_box.min.y);
        float z_overlap = std::min(player_box.max.z, platform_box.max.z) -
                          std::max(player_box.min.z, platform_box.min.z);

        if (y_overlap < x_overlap && y_overlap < z_overlap)
        {
            float dir = (player->position.y > platform.position.y) ? 1.0f : -1.0f;
            player->position.y += y_overlap * dir;
            if (dir > 0 && player->velocity_y <= 0)
            {
                player->velocity_y = 0.0f;
                player->jumps_remaining = MAX_JUMP;
            }
            else if (dir < 0)
                player->velocity_y = 0.0f;
        }
        else if (x_overlap < z_overlap)
        {
            float dir = (player->position.x > platform.position.x) ? 1.0f : -1.0f;
            player->position.x += x_overlap * dir;
        }
        else
        {
            float dir = (player->position.z > platform.position.z) ? 1.0f : -1.0f;
            player->position.z += z_overlap * dir;
        }
    }
}

void player_ball_collision(Player* player, Ball* ball)
{
    BoundingBox player_box = make_bounding_box(player->position, player->size);

    if (!CheckCollisionBoxSphere(player_box, ball->position, ball->radius))
        return;

    Vector3 dir = Vector3Subtract(ball->position, player->position);
    dir.y = 0.0f;
    dir = Vector3Normalize(dir);
    if (IsKeyDown(KEY_E)) // a "lob", dampen horizontals and boost verticality
    {
        ball->vx += dir.x * KICK_FORCE * 0.6;
        ball->vy += LOB_FORCE;
        ball->vz += dir.z * KICK_FORCE * 0.6;
    }
    else
    {
        ball->vx += dir.x * KICK_FORCE;
        ball->vy += dir.y * KICK_FORCE;
        ball->vz += dir.z * KICK_FORCE;
    }
}
