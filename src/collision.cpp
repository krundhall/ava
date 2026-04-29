#include "collision.h"
#include "constants.h"
#include <algorithm>
#include <raylib.h>
#include <raymath.h>

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
    if (IsKeyDown(KEY_E))
    {
        ball->vx += dir.x * KICK_FORCE * 0.7f;
        ball->vy += LOB_FORCE;
        ball->vz += dir.z * KICK_FORCE * 0.7f;
    }
    else
    {
        ball->vx += dir.x * KICK_FORCE;
        ball->vy += dir.y * KICK_FORCE;
        ball->vz += dir.z * KICK_FORCE;
    }
}

void ball_box_collision(Ball* ball, const std::vector<Box> &platforms)
{


    Vector3 ball_size = {ball->radius * 2, ball->radius * 2, ball->radius * 2};

    for (const auto &platform : platforms)
    {
        BoundingBox ball_box = make_bounding_box(ball->position, ball_size);
        BoundingBox platform_box = make_bounding_box(platform.position, platform.size);

        if (!CheckCollisionBoxes(ball_box, platform_box))
            continue;

        float x_overlap = std::min(ball_box.max.x, platform_box.max.x) -
                          std::max(ball_box.min.x, platform_box.min.x);
        float y_overlap = std::min(ball_box.max.y, platform_box.max.y) -
                          std::max(ball_box.min.y, platform_box.min.y);
        float z_overlap = std::min(ball_box.max.z, platform_box.max.z) -
                          std::max(ball_box.min.z, platform_box.min.z);

        if (y_overlap < x_overlap && y_overlap < z_overlap)
        {
            float dir = (ball->position.y > platform.position.y) ? 1.0f : -1.0f;
            ball->position.y += y_overlap * dir;
            if (dir > 0 && ball->vy <= 0)
                ball->vy = 0.0f;
            else if (dir < 0)
                ball->vy = 0.0f;
        }
        else if (x_overlap < z_overlap)
        {
            float dir = (ball->position.x > platform.position.x) ? 1.0f : -1.0f;
            ball->position.x += x_overlap * dir;
            ball->vx = 0.0f;
        }
        else
        {
            float dir = (ball->position.z > platform.position.z) ? 1.0f : -1.0f;
            ball->position.z += z_overlap * dir;
            ball->vz = 0.0f;
        }
    }
}

void run_collisions(Player* player, Ball* ball, const std::vector<Box> &platforms)
{
    check_collision(player, platforms);
    ball_box_collision(ball, platforms);
    player_ball_collision(player, ball);
}
