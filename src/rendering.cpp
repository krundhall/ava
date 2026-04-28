#include "rendering.h"

void draw(const GameCamera* camera, const Player* player)
{
    BeginDrawing();
    ClearBackground(GRAY);

    BeginMode3D(camera->cam3d);
    player_draw(player);
    DrawCubeWires(player->position, 2.0f, 2.0f, 2.0f, MAROON);
    DrawGrid(10, 1.0f);
    EndMode3D();

    DrawText("Ava", 10, 40, 20, DARKGRAY);
    DrawFPS(10, 10);

    EndDrawing();
}
