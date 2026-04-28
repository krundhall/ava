#pragma once
#include <raylib.h>
#include <raymath.h>

struct Box
{
    Vector3 position;
    Vector3 size;
    Color color;
};

inline BoundingBox make_bounding_box(Vector3 position, Vector3 size)
{
    BoundingBox box;
    box.min = {position.x - size.x / 2, position.y - size.y / 2, position.z - size.z / 2};
    box.max = {position.x + size.x / 2, position.y + size.y / 2, position.z + size.z / 2};
    return box;
}
