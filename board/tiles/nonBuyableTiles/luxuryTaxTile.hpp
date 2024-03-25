#pragma once

// Project headers
#include "../tile.hpp"

class LuxuryTaxTile : public Tile
{
public:
    // Constructors
    LuxuryTaxTile();

    // Methods
    void runTileAction(Player *player) override;
};