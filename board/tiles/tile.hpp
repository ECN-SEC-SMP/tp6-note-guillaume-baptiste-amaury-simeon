#pragma once

// System headers
#include <string>

// Project header
#include "../../player/player.hpp"

using namespace std;

class Tile
{
private:
    string _name = "";

public:
    Tile(string name);

    // Getters
    string getName(void);

    // Setters
    void setName(string name);

    // Methods
    virtual void runTileAction(Player *player) = 0;
};