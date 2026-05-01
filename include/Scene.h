#pragma once
#include <memory>

class Scene
{
private:
public:
    virtual std::unique_ptr<Scene> update(float dt) = 0;
    virtual void draw() = 0;
    virtual ~Scene() = default;

protected:
    void updateCamera();
    void drawHUD();
    void drawFPS();
};
