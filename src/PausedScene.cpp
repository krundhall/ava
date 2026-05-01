#include "PausedScene.h"
#include "PlayingScene.h"
#include <raylib.h>

PausedScene::PausedScene(GameWorld& world)
: world(world) {}

std::unique_ptr<Scene> PausedScene::update(float /*dt*/) {
    if (IsKeyPressed(KEY_ESCAPE))
        return std::make_unique<PlayingScene>(world);

    return nullptr;
}

void PausedScene::draw() {
    // draw the game world behind the pause menu
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {0, 0, 0, 150});
    DrawText("PAUSED", GetScreenWidth() / 2 - 40, GetScreenHeight() / 2, 20, RAYWHITE);
}
