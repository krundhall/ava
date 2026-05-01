#pragma once
#include "Scene.h"
#include "GameWorld.h"
#include <memory>

class PausedScene : public Scene
{
public:
    PausedScene(GameWorld& world);
    std::unique_ptr<Scene> update(float dt) override;
    void draw() override;

private:
    GameWorld& world;
};
