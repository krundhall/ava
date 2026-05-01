#pragma once
#include <raylib.h>

class Ball
{
private:
    Vector2 position;
    Vector2 velocity;
    float radius;
    Color color;
public:
    void update(float dt);
    void draw();
};
