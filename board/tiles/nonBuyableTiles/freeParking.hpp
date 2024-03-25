#pragma once

// Project headers
#include "../tile.hpp"

class FreeParking : public Tile
{
public:
    // Constructors
    FreeParking();

    // Methods
    void runTileAction(Player *player) override;
};