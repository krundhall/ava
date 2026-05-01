#pragma once
#include "Player.h"
#include "Ball.h"
struct GameWorld {
    Player playerLeft  = Player(PlayerSide::LEFT);
    Player playerRight = Player(PlayerSide::RIGHT);
    Ball ball;
    int scoreLeft = 0;
    int scoreRight = 0;
};
