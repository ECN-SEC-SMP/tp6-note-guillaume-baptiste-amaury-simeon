#pragma once

// Project headers
#include "../tile.hpp"

class CommunityTile : public Tile
{
public:
    // Constructors
    CommunityTile();

    // Methods
    void runTileAction(Player *player) override;
};