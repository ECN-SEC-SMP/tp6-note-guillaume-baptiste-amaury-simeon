#pragma once

// System headers
#include <vector>

// Project headers
#include "tiles/tile.hpp"
#include "../constants.h"

using namespace std;

class Board
{
private:
    vector<Player> _players = vector<Player>();
    vector<Tile> _tiles;

    int _availableHouses = kDefaultGameHouses;
    int _availableHotels = kDefaultGameHotels;

    void addOneTile(Tile &tile);
    void addOnePlayer(Player &player);

public:
    // Constructors
    Board();

    // Getters
    vector<Player> getPlayers(void);
    vector<Tile> getTiles(void);
    int getAvailableHouses(void);
    int getAvailableHotels(void);

    // Setters
    void setPlayers(vector<Player> players);
    void setTiles(vector<Tile> tiles);
    void setAvailableHouses(int availableHouses);
    void setAvailableHotels(int availableHotels);

    // Methods
    void initBoard(void);
    void registerPlayers(void);

    void playOneGlobalTurn(void);
    void playOnePlayerTurn(Player &player);

    bool hasColorMonopoly(Color color) const;
    bool CanConstructNewHouse(Color color, int newHouses) const;
    bool CanConstructHotel(Color color) const;


};