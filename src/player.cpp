#include "player.h"
#include "constants.h"
#include <math.h>
#include <raylib.h>
#include <raymath.h>

void player_update(Player* player, float dt)
{
    /* Build the move vector*/
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

    /* Horizontal Physics */
    player->velocity_x += move.x * player->speed * dt;
    player->velocity_z += move.z * player->speed * dt;
    player->position.x += player->velocity_x * dt;
    player->position.z += player->velocity_z * dt;


    /* Jump Logic */
    if (IsKeyPressed(KEY_SPACE))
        player->jump_buffer_timer = 0.25f;

    if (player->jump_buffer_timer > 0 && player->jumps_remaining > 0)
    {
        player->velocity_y =
            (player->jumps_remaining == 1) ? player->double_jump_force : player->jump_force;
        player->jumps_remaining--;
        player->jump_buffer_timer = 0.0f;
    }
    if (IsKeyReleased(KEY_SPACE) && player->velocity_y > 0)
        player->velocity_y *= EARLY_JUMP_CUT;

    /* Gravity and friction forces */
    player->velocity_y -= GRAVITY * dt;
    player->velocity_x *= FRICTION;
    player->velocity_z *= FRICTION;
    player->position.y += player->velocity_y * dt;
    player->jump_buffer_timer -= dt;

    /* Ground check */
    if (player->position.y <= 0.0f)
    {
        player->position.y = 0.0f;
        player->velocity_y = 0.0f;
        player->jumps_remaining = MAX_JUMP;
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
