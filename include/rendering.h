#pragma once
#include "ball.h"
#include "camera.h"
#include "object.h"
#include "player.h"
#include <vector>

void draw(const GameCamera* camera, const Player* player, const std::vector<Box> &platforms,
          const Ball &ball);
