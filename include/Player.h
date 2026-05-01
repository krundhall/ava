#pragma once
#include "raylib.h"

class Player
{
public:
    float speed;
    Vector2 position;
    Vector2 size;
    Color color;
public:
    Player();

    void player_update(float dt);


};
