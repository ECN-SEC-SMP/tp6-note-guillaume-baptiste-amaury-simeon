#pragma once

// Project headers
#include "../tile.hpp"

class StartTile : public Tile
{
public:
    // Constructors
    StartTile();

    // Methods
    void runTileAction(Player *player) override;
};