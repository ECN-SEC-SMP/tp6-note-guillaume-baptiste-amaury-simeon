#pragma once

// Project headers
#include "../tile.hpp"

class PrisonTile : public Tile
{
public:
    // Constructors
    PrisonTile();

    // Methods
    void runTileAction(Player *player) override;
};