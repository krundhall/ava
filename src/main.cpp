#include "constants.h"
#include <raylib.h>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetTargetFPS(120);

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};


    Camera3D camera = {
        {cubePosition.x, cubePosition.y + 10.0f, cubePosition.z + 10.0f}, // position
        {cubePosition},                                                   // target
        {0.0f, 1.0f, 0.0f},                                               // up
        45.0f,                                                            // fovy
        CAMERA_PERSPECTIVE                                                // projection
    };


    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyDown(KEY_W))
            cubePosition.z -= 0.2f;
        if (IsKeyDown(KEY_S))
            cubePosition.z += 0.2f;
        if (IsKeyDown(KEY_D))
            cubePosition.x += 0.2f;
        if (IsKeyDown(KEY_A))
            cubePosition.x -= 0.2f;

        camera.position = {cubePosition.x, cubePosition.y + 10.0f, cubePosition.z + 10.0f};
        camera.target = cubePosition;

        // Draw
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        BeginMode3D(camera);
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        DrawGrid(10, 1.0f);
        EndMode3D();

        DrawText("Ava", 10, 40, 20, DARKGRAY);
        DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
