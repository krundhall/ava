#include "MenuScene.h"
#include "PlayingScene.h"
#include <raylib.h>

MenuScene::MenuScene(GameWorld& world)
: world(world) {}

std::unique_ptr<Scene> MenuScene::update(float dt) {
    if (IsKeyPressed(KEY_ENTER))
        return std::make_unique<PlayingScene>(world);

    return nullptr;
}

void MenuScene::draw() {
    DrawText("AVA", GetScreenWidth() / 2 - 20, 200, 40, RAYWHITE);
    DrawText("Press ENTER to play", GetScreenWidth() / 2 - 80, 300, 20, GRAY);
}
