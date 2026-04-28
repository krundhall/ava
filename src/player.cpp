#include "player.h"
#include "constants.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>

void player_update(Player* player, float dt)
{
    float rad = player->facing * DEG2RAD;
    float fx = -sinf(rad);
    float fz = -cosf(rad);
    float rx = cosf(rad);
    float rz = -sinf(rad);

    Vector3 move = {0.0f, 0.0f, 0.0f};
    if (IsKeyDown(KEY_W))
    {
        move.x += fx;
        move.z += fz;
    }
    if (IsKeyDown(KEY_S))
    {
        move.x -= fx;
        move.z -= fz;
    }
    if (IsKeyDown(KEY_A))
    {
        move.x -= rx;
        move.z -= rz;
    }
    if (IsKeyDown(KEY_D))
    {
        move.x += rx;
        move.z += rz;
    }

    if (Vector3Length(move) > 0)
        move = Vector3Normalize(move);

    player->position.x += move.x * player->speed * dt;
    player->position.z += move.z * player->speed * dt;

    if (IsKeyPressed(KEY_SPACE) && player->jumps_remaining > 0)
    {
        player->velocity_y =
            (player->jumps_remaining == 1) ? player->double_jump_force : player->jump_force;
        player->jumps_remaining--;
    }

    player->velocity_y -= GRAVITY * dt;
    player->position.y += player->velocity_y * dt;

    if (player->position.y <= 0.0f)
    {
        player->position.y = 0.0f;
        player->velocity_y = 0.0f;
        player->jumps_remaining = MAX_YUMP;
    }
}

void player_draw(const Player* player)
{
    DrawCube(player->position, 2.0f, 2.0f, 2.0f, GREEN);
    DrawCubeWires(player->position, 2.0f, 2.0f, 2.0f, WHITE);

    float rad = player->facing * DEG2RAD;
    Vector3 cone_base = {player->position.x - sinf(rad) * 1.0f,
                         player->position.y,
                         player->position.z - cosf(rad) * 1.0f};
    Vector3 cone_tip = {player->position.x - sinf(rad) * 2.5f,
                        player->position.y,
                        player->position.z - cosf(rad) * 2.5f};
    DrawCylinderEx(cone_base, cone_tip, 0.5f, 0.0f, 8, RED);
}
