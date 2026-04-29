#include "ball.h"
#include "constants.h"

void ball_update(Ball* ball, float dt)
{
    ball->vx *= BALL_FRICTION;
    ball->vy -= GRAVITY * dt;
    ball->vz *= BALL_FRICTION;

    ball->position.x += ball->vx * dt;
    ball->position.y += ball->vy * dt;
    ball->position.z += ball->vz * dt;

    if (ball->position.y <= ball->radius)
    {
        ball->position.y = ball->radius;
        ball->vy = 0.0f;
    }
}

void ball_draw(const Ball* ball)
{
    DrawSphere(ball->position, ball->radius, RAYWHITE);
    DrawSphereWires(ball->position, ball->radius, 1, 1, BLACK);
    DrawCircle3D(
        {ball->position.x, 0.1f, ball->position.z}, ball->radius * 0.5f, {1, 0, 0}, 90.0f, BLACK);
}
