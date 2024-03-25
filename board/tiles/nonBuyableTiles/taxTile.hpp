#pragma once

// Project headers
#include "../tile.hpp"

class TaxTile : public Tile
{
public:
    // Constructors
    TaxTile();

    // Methods
    void runTileAction(Player *player) override;
};