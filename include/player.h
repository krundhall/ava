#pragma once
#include <raylib.h>

struct Player
{
    Vector3 position = {0.0f, 0.0f, 0.0f};
    float speed = 15.0f;
};


void player_update(Player* player, float dt);
