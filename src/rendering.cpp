#include "rendering.h"
void draw(const GameCamera* camera, const Player* player, const std::vector<Box> &platforms,
          const Ball &ball)
{
    BeginDrawing();
    ClearBackground({135, 206, 235, 255});

    BeginMode3D(camera->cam3d);
    player_draw(player);
    ball_draw(&ball);
    for (const auto &platform : platforms)
    {
        DrawCube(
            platform.position, platform.size.x, platform.size.y, platform.size.z, platform.color);
        DrawCubeWires(platform.position, platform.size.x, platform.size.y, platform.size.z, BLACK);
    }

    DrawGrid(50, 1.0f);
    EndMode3D();

    DrawText("Ava", 10, 40, 20, DARKGRAY);
    DrawFPS(10, 10);

    EndDrawing();
}
