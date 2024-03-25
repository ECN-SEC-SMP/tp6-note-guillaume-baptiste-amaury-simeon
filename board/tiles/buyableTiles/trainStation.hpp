#pragma once

// System headers
#include <string>

// Project headers
#include "buyableTile.hpp"

using namespace std;

class TrainStation : public BuyableTile
{
public:
    // Constructors
    TrainStation(string Name, int price);
    TrainStation(string Name, int price, Player *player);

    // Methods
    void runTileAction(Player *player) override;
};
