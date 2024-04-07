// System headers
#include <stdexcept>
#include <time.h>

// Project headers
#include "player.hpp"
#include "../board/tiles/buyableTiles/buyableTile.hpp"
#include "../board/tiles/buyableTiles/land.hpp"
#include "../board/tiles/buyableTiles/publicService.hpp"
#include "../board/tiles/buyableTiles/trainStation.hpp"

/******
 * Getters
 * ******/
string Player::getName(void) { return _name; }
int Player::getPosition(void) { return _position; }
int Player::getMoney(void) { return _money; }
vector<unique_ptr<Tile>> Player::getOwnedTiles(void) { return _ownedTiles; }
int Player::getDiceDoubles(void) { return _diceDoubles; }
bool Player::isInJail(void) { return _inJail; }
bool Player::isBroke(void) { return _broke; }

/******
 * Setters
 * ******/
void Player::setName(string name) { _name = name; };
void Player::setPosition(int position) { _position = position; }
void Player::setMoney(int money) { _money = money; }
void Player::setOwnedTiles(vector<unique_ptr<Tile>> ownedTiles) { _ownedTiles = ownedTiles; }
void Player::setDiceDoubles(int diceDoubles) { _diceDoubles = diceDoubles; }
void Player::setJailState(bool inJail) { _inJail = inJail; }
void Player::setBrokeState(bool broke) { _broke = broke; }

/******
 * Constructor
 * ******/
Player::Player(string name, int money)
{
    _name = name;
    _money = money;
}

/******
 * Methods
 * ******/
void Player::addMoney(int amount)
{
    _money += amount;
}

bool Player::removeMoney(int amount)
{
    {
        if (_money < amount)
        {
            _money = 0;
            _broke = true;
            return true;
        }
        else
        {
            _money -= amount;
            return false;
        }
    }
}

int Player::launchOneDice(void)
{
    srand(time(0));
    return ((rand() % 6) + 1);
}

int Player::launchDices(void)
{
    int d1, d2, res = 0;
    d1 = launchOneDice();
    d2 = launchOneDice();

    if (d1 == d2)
    {
        addDiceDouble();
    }

    return (d1 + d2);
}

void Player::addDiceDouble(void)
{
    _diceDoubles += 1;
    if (_diceDoubles == 3)
    {
        _inJail = true;
        resetDiceDoubles();
    }

    // Exception catching
    if (_diceDoubles > 3)
    {
        throw logic_error("Dice doubles cannot be superior to 3.");
    }
}

void Player::resetDiceDoubles(void)
{
    _diceDoubles = 0;
}

void Player::addOneOwnedTile(Tile &tile)
{
    // Supposed to check the tile is not owned twice...
    switch (tile.getType())
    {
    case eLand:
        _ownedTiles.push_back(make_unique<Land>(tile));
        break;

    case ePublicservice:
        _ownedTiles.push_back(make_unique<PublicService>(tile));
        break;

    case eTrainStation:
        _ownedTiles.push_back(make_unique<TrainStation>(tile));
        break;

    default:
        throw logic_error("A player can only own a buyable tile");
        break;
    }
}
