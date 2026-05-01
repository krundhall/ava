#include "Player.h"

Player::Player(PlayerSide side)
: speed(500), side(side), radius(40)
{
    if (side == PlayerSide::LEFT) {
        position = { 200, 400 };
        color = BLUE;
    } else {
        position = { 600, 400 };
        color = RED;
    }
}

void Player::update(float dt)
{
    if (side == PlayerSide::LEFT) {
        if (IsKeyDown(KEY_W)) position.y -= speed * dt;
        if (IsKeyDown(KEY_S)) position.y += speed * dt;
        if (IsKeyDown(KEY_A)) position.x -= speed * dt;
        if (IsKeyDown(KEY_D)) position.x += speed * dt;
    } else {
        if (IsKeyDown(KEY_UP))    position.y -= speed * dt;
        if (IsKeyDown(KEY_DOWN))  position.y += speed * dt;
        if (IsKeyDown(KEY_LEFT))  position.x -= speed * dt;
        if (IsKeyDown(KEY_RIGHT)) position.x += speed * dt;
    }
}

void Player::draw()
{
    DrawCircleV(this->position, this->radius, this->color);
}
