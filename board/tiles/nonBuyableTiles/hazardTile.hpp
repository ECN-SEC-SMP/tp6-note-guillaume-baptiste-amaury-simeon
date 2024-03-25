#pragma once

// Project headers
#include "../tile.hpp"

class HazardTile : public Tile
{
public:
    // Constructors
    HazardTile();

    // Methods
    void runTileAction(Player *player) override;
};