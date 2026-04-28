#pragma once
#include <raylib.h>

struct GameCamera
{
    Camera3D cam3d;
    float yaw;
    float pitch;
    float radius;
};

GameCamera camera_create(Vector3 target, float pitch, float radius);
void camera_update(GameCamera *cam, Vector3 target, float *player_facing);
