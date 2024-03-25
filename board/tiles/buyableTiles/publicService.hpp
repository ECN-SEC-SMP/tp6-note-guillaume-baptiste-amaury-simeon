#pragma once

// System headers
#include <string>

// Project headers
#include "buyableTile.hpp"

using namespace std;

class PublicService : public BuyableTile
{
public:
    // Constructors
    PublicService(string Name, int price);
    PublicService(string Name, int price, Player *player);

    // Methods
    void runTileAction(Player *player) override;
};
