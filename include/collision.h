#pragma once
#include "ball.h"
#include "object.h"
#include "player.h"
#include <vector>

void check_collision(Player* player, const std::vector<Box> &platforms);
void player_ball_collision(Player* player, Ball* ball);
void ball_box_collision(Ball* ball, const std::vector<Box> &platforms);
void run_collisions(Player* player, Ball* ball, const std::vector<Box> &platforms);
