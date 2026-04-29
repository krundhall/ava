#pragma once
#include <raylib.h>
#include <raymath.h>

struct Ball
{
    Vector3 position;
    float radius;
    Color color;
    float vx;
    float vy;
    float vz;
};

void ball_update(Ball* ball, float dt);
void ball_draw(const Ball* ball);
