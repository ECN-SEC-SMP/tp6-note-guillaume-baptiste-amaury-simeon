#pragma once

// System headers
#include <string>

// Project headers
#include "buyableTile.hpp"
#include "../../../constants.h"

using namespace std;

class Land : public BuyableTile
{
private:
    Color _color = eNoColor;
    int _houses = 0;
    bool _hotel = false;

public:
    // Constructors
    Land(string Name, int price, Color color, int mortgagePrice);
    Land(string Name, int price, Color color, int mortgagePrice, Player *player);

    // Getters
    Color getColor(void);
    int getHouses(void);
    bool hasHotel(void);

    // Setters
    void setColor(Color color);
    void setHouses(int houses);
    void setHotel(bool hotel);

    // Methods
    void addOneHouse(void); // Should remove a house from the board count
    void addOneHotel(void); // Should remove a hotel from the board count
    void runTileAction(Player *player) override;
};
