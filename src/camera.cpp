#include "camera.h"
#include <raymath.h>

static void camera_recalculate(GameCamera *cam, Vector3 target)
{
    float yaw_rad   = cam->yaw   * DEG2RAD;
    float pitch_rad = cam->pitch * DEG2RAD;

    cam->cam3d.position.x = target.x + cam->radius * cosf(pitch_rad) * sinf(yaw_rad);
    cam->cam3d.position.y = target.y + cam->radius * sinf(pitch_rad);
    cam->cam3d.position.z = target.z + cam->radius * cosf(pitch_rad) * cosf(yaw_rad);
    cam->cam3d.target     = target;
}

GameCamera camera_create(Vector3 target, float pitch, float radius)
{
    GameCamera cam;
    cam.yaw    = 0.0f;
    cam.pitch  = pitch;
    cam.radius = radius;
    cam.cam3d.up         = {0.0f, 1.0f, 0.0f};
    cam.cam3d.fovy       = 45.0f;
    cam.cam3d.projection = CAMERA_PERSPECTIVE;
    camera_recalculate(&cam, target);
    return cam;
}

void camera_update(GameCamera *cam, Vector3 target, float *player_facing)
{
    bool rotating = IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsMouseButtonDown(MOUSE_BUTTON_RIGHT);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        DisableCursor();
    if (!rotating && (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) || IsMouseButtonReleased(MOUSE_BUTTON_RIGHT)))
        EnableCursor();

    if (rotating)
    {
        Vector2 delta = GetMouseDelta();
        cam->yaw   -= delta.x * 0.18f;
        cam->pitch += delta.y * 0.18f;
        cam->pitch  = Clamp(cam->pitch, 10.0f, 80.0f);
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        *player_facing = cam->yaw;

    cam->radius -= GetMouseWheelMove() * 1.0f;
    cam->radius  = Clamp(cam->radius, 2.0f, 30.0f);

    camera_recalculate(cam, target);
}
