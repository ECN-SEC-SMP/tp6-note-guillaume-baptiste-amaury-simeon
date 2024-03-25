#pragma once

// Project headers
#include "../tile.hpp"

class GoToPrison : public Tile
{
public:
    // Constructors
    GoToPrison();

    // Methods
    void runTileAction(Player *player) override;
};