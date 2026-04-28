#pragma once
#include <raylib.h>

struct Player
{
    Vector3 position = {0.0f, 0.0f, 0.0f};
    float speed = 15.0f;
    float facing = 0.0f;
    float velocity_y = 0.0f;
    int jumps_remaining = 2;
    float jump_force = 11.0f;
    float double_jump_force = 14.0f;
};


void player_update(Player* player, float dt);
void player_draw(const Player* player);
