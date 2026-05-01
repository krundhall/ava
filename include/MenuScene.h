#pragma once
#include "Scene.h"
#include "GameWorld.h"

class MenuScene : public Scene
{
private:
    GameWorld &world;
public:
    MenuScene(GameWorld& world);
    std::unique_ptr<Scene> update(float dt) override;
    void draw() override;

};
