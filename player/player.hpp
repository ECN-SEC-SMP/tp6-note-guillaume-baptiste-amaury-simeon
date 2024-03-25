#pragma once

using namespace std;

// System headers
#include <string>
#include <vector>

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

    vector<Tile> _ownedTiles = vector<Tile>();

    int _diceDoubles = 0;
    bool _inJail = false;

protected:
    int launchOneDice(void);
    void addDiceDouble(void);

public:
    // Getters
    string getName(void);
    int getPosition(void);
    int getMoney(void);
    vector<Tile> getOwnedTiles(void);
    int getDiceDoubles(void);
    bool isInJail(void);
    bool isBroke(void);

    // Setters
    void setName(string name);
    void setPosition(int position);
    void setMoney(int money);
    void setOwnedTiles(vector<Tile> ownedTiles);
    void setDiceDoubles(int diceDoubles);
    void setJailState(bool inJail);
    void setBrokeState(bool broke);

    // Methods
    void addMoney(int amount);
    bool removeMoney(int amount);

    int launchOneDice(void);
    void addDiceDouble(void);
    void resetDiceDoubles(void);

    void addOneOwnedTile(Tile &tile);
};
