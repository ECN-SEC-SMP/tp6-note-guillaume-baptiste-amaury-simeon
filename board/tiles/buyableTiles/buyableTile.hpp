#pragma once

// Project headers
#include "../tile.hpp"

class BuyableTile : public Tile
{
private:
    // Constant value
    const int _mortgagePrice;
    bool _mortgageStatus = false;
    int _price = 0;
    Player *_player = nullptr;

protected:
    void runAuction(Player &excludedPlayer); // If the player does not buy this Tile then an auction occures

public:
    // Constructors
    BuyableTile(string name, int price, Player *player, int mortgagePrice);
    BuyableTile(string name, int price, int mortgagePrice);

    // Getters
    int getPrice(void);
    Player *getPlayer(void);
    bool isMortgaged(void);

    // Setters
    void setPrice(int price);
    void setPlayer(Player *player);
    void setMortgageStatus(bool _mortgageStatus);

    // Methods
    virtual void runTileAction(Player *player) = 0;
};