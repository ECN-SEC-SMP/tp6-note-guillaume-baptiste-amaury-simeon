#pragma once

using namespace std;

// System headers
#include <string>
#include <vector>
#include <memory>

// Project headers
#include "../board/tiles/tile.hpp"
#include "../constants.h"

class Player
{
private:
    string _name = "";
    int _money = kDefaultMoneyAmount;
    int _position = 0;
    bool _broke = false;

    vector<unique_ptr<Tile>> _ownedTiles = vector<unique_ptr<Tile>>();

    int _diceDoubles = 0;
    bool _inJail = false;

protected:
    int launchOneDice(void);
    void addDiceDouble(void);
    void resetDiceDoubles(void);

public:
    // Constructors
    Player(string name, int money);

    // Getters
    string getName(void);
    int getPosition(void);
    int getMoney(void);
    vector<unique_ptr<Tile>> getOwnedTiles(void);
    int getDiceDoubles(void);
    bool isInJail(void);
    bool isBroke(void);

    // Setters
    void setName(string name);
    void setPosition(int position);
    void setMoney(int money);
    void setOwnedTiles(vector<unique_ptr<Tile>> ownedTiles);
    void setDiceDoubles(int diceDoubles);
    void setJailState(bool inJail);
    void setBrokeState(bool broke);

    // Methods
    void addMoney(int amount);
    bool removeMoney(int amount);

    int launchDices(void);

    void addOneOwnedTile(Tile &tile);
};
