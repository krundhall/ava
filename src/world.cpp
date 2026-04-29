#include "world.h"

std::vector<Box> build_platform_vector()
{
    std::vector<Box> platform_vector;

    platform_vector.push_back(Box{{0.0f, 2.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE});
    platform_vector.push_back(Box{{20.0f, 3.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE});
    platform_vector.push_back(Box{{40.0f, 4.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE});
    platform_vector.push_back(Box{{60.0f, 5.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE});
    platform_vector.push_back(Box{{80.0f, 6.0f, -20.0f}, {10.0f, 2.0f, 10.0f}, BLUE});

    platform_vector.push_back(Box{{0.0f, 2.5f, 25.0f}, {35.0f, 5.0f, 2.5f}, DARKGREEN});
    platform_vector.push_back(
        Box{{0.0f, -0.25f, 0.0f}, {200.0, 0.5f, 200.0f}, {194, 178, 128, 255}});
    return platform_vector;
}
