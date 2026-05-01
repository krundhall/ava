#pragma once
#include "Scene.h"
#include "GameWorld.h"
#include <memory>

class PlayingScene : public Scene
{
public:
    PlayingScene(GameWorld& world);
    std::unique_ptr<Scene> update(float dt) override;
    void draw() override;

private:
    GameWorld& world;
};
