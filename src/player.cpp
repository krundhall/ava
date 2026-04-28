#include "player.h"
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

    if (IsKeyDown(KEY_W))
    {
        player->position.x += fx * player->speed * dt;
        player->position.z += fz * player->speed * dt;
    }
    if (IsKeyDown(KEY_S))
    {
        player->position.x -= fx * player->speed * dt;
        player->position.z -= fz * player->speed * dt;
    }

    if (IsKeyDown(KEY_A))
    {
        player->position.x -= rx * player->speed * dt;
        player->position.z -= rz * player->speed * dt;
    }
    if (IsKeyDown(KEY_D))
    {
        player->position.x += rx * player->speed * dt;
        player->position.z += rz * player->speed * dt;
    }
}

void player_draw(const Player* player)
{
    DrawCube(player->position, 2.0f, 2.0f, 2.0f, RED);

    float rad = player->facing * DEG2RAD;
    Vector3 cone_base = {
        player->position.x - sinf(rad) * 1.0f,
        player->position.y,
        player->position.z - cosf(rad) * 1.0f
    };
    Vector3 cone_tip = {
        player->position.x - sinf(rad) * 2.5f,
        player->position.y,
        player->position.z - cosf(rad) * 2.5f
    };
    DrawCylinderEx(cone_base, cone_tip, 0.5f, 0.0f, 8, BLUE);
}
