#include "rendering.h"

void draw(const GameCamera* camera, const Player* player, const Box* platform)
{
    BeginDrawing();
    ClearBackground(GRAY);

    BeginMode3D(camera->cam3d);
    player_draw(player);

    DrawCube(platform->position, platform->size.x, platform->size.y, platform->size.z, BLUE);
    DrawCubeWires(platform->position, platform->size.x, platform->size.y, platform->size.z, BLACK);

    DrawGrid(10, 1.0f);
    EndMode3D();

    DrawText("Ava", 10, 40, 20, DARKGRAY);
    DrawFPS(10, 10);

    EndDrawing();
}
