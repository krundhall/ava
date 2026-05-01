#include "PlayingScene.h"
#include "PausedScene.h"
#include <raylib.h>

PlayingScene::PlayingScene(GameWorld& world)
: world(world) {}

std::unique_ptr<Scene> PlayingScene::update(float dt) {
    world.playerLeft.update(dt);
    world.playerRight.update(dt);

    if (IsKeyPressed(KEY_P))
        return std::make_unique<PausedScene>(world);

    return nullptr;
}

void PlayingScene::draw()
{
    world.playerLeft.draw();
    world.playerRight.draw();
}
