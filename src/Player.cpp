#include "Player.h"

Player::Player()
: speed(300), position({400, 400}), size({30,30}), color(RAYWHITE)
{
}

void Player::player_update(float dt)
{
    if (IsKeyDown(KEY_W))
    {
        this->position.y -= speed * dt;
    }
    if (IsKeyDown(KEY_S))
    {
        this->position.y += speed * dt;
    }
    if (IsKeyDown(KEY_A))
    {
        this->position.x -= speed * dt;
    }
    if (IsKeyDown(KEY_D))
    {
        this->position.x += speed * dt;
    }
}
