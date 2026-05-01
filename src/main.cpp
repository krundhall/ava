#include "constants.h"
#include "GameWorld.h"
#include "PlayingScene.h"
#include <raylib.h>
#include "MenuScene.h"
#include <memory>

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ava");
    SetExitKey(KEY_NULL);
    SetTargetFPS(120);

    GameWorld world;
    std::unique_ptr<Scene> scene = std::make_unique<MenuScene>(world);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        auto next = scene->update(dt);
        if (next) scene = std::move(next);

        BeginDrawing();
            ClearBackground(GRAY);
            scene->draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
