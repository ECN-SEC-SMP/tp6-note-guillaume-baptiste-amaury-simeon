#pragma once

// Land color (subclass of tile)
enum Color
{
    eNoColor = -1,
    eGreen = 1,
    eBlue,
    ePurple,
    eLightBlue,
    eLightPurple,
    eOrange,
    eRed,
    eYellow,
};

// Player
const int kDefaultMoneyAmount = 500;

// Board
const int kDefaultGameHotels = 12;
const int kDefaultGameHouses = 36;