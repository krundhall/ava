#include "player.h"

void player_update(Player* player, float dt)
{
    if (IsKeyDown(KEY_W))
        player->position.z -= player->speed * dt;
    if (IsKeyDown(KEY_S))
        player->position.z += player->speed * dt;
    if (IsKeyDown(KEY_D))
        player->position.x += player->speed * dt;
    if (IsKeyDown(KEY_A))
        player->position.x -= player->speed * dt;
}
