#pragma once

// System headers
#include <string>

// Project header
#include "../../player/player.hpp"
#include "../../constants.h"

using namespace std;

class Tile
{
private:
    string _name = "";
    TileType _type = eNoType;

public:
    Tile(string name, TileType type);

    // Getters
    string getName(void);
    TileType getType(void);

    // Setters
    void settype(TileType type);
    void setName(string name);

    // Methods
    virtual void runTileAction(Player *player) = 0;
};