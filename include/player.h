#pragma once
#include "constants.h"
#include <raylib.h>
struct Player
{
    Vector3 position = {0.0f, 0.0f, 0.0f};
    float speed = 270.0f;
    float facing = 0.0f;
    float velocity_x = 0.0f;
    float velocity_y = 0.0f;
    float velocity_z = 0.0f;
    int jumps_remaining = MAX_JUMP;
    float jump_force = 13.0f; // 11, 14
    float double_jump_force = 15.0f;
    Vector3 size = {2.0f, 2.0f, 2.0f};
    float jump_buffer_timer = 0.0f;
};


void player_update(Player* player, float dt);
void player_draw(const Player* player);
