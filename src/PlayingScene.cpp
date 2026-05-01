#include "PlayingScene.h"
#include <raylib.h>
#include "PausedScene.h"

PlayingScene::PlayingScene(GameWorld& world)
: world(world) {}

std::unique_ptr<Scene> PlayingScene::update(float dt) {
    world.player.player_update(dt);

    if (IsKeyPressed(KEY_ESCAPE))
        return std::make_unique<PausedScene>(world);

    return nullptr;
}

void PlayingScene::draw()
{
    DrawRectangleV(world.player.position, world.player.size, world.player.color);
}
