#include "board.hpp"
#include <iostream>


using namespace std; 

// Constructors
Board::Board(){

}

void Board::addOneTile(Tile &tile){
    vector<Tile> newTiles = getTiles(); 
    newTiles.push_back(tile); 
    setTiles(newTiles); 
}

void Board::addOnePlayer(Player &player){
    vector<Player> newPlayers =getPlayers();
    newPlayers.push_back(player);
    setPlayers(newPlayers);
}

// Getters
vector<Player> Board::getPlayers(void){
    return this->_players; 
}

vector<Tile> Board::getTiles(void){
    return this->_tiles;
}

int Board::getAvailableHouses(void){
    return this->_availableHouses;
}

int Board::getAvailableHotels(void){
    return this->_availableHotels; 
}

// Setters
void Board::setPlayers(vector<Player> players){
    this->_players = players; 
}

void Board::setTiles(vector<Tile> tiles){
    this->_tiles = tiles; 
}

void Board::setAvailableHouses(int availableHouses){
    this->_availableHouses = availableHouses;
}

void Board::setAvailableHotels(int availableHotels){
    this->_availableHotels = availableHotels; 
}

// Methods
void Board::initBoard(void){
    // init tiles 
    // init players 
    int nbPlayers; 
    cout << "How many players are you ? " << endl;
    cin >> nbPlayers; 

    if (nbPlayers < 2 ){
        cout << "You are not enouth players. " << endl; 
    }
    else if (nbPlayers >8){
        cout << "You are to much players. " << endl; 
    }
    else {
        cout << "" << endl; 
        for (int i = 0; i < nbPlayers; i++){
            registerPlayers(); 
        }
    }
}

void Board::registerPlayers(void){
    string playerName; 
    cout << "What's the name of the player ?"<< endl; 
    cin >> playerName;  
    
    Player newPlayer = Player(playerName); 
    addOnePlayer(newPlayer); 
}

void Board::playOneGlobalTurn(void){

}

void Board::playOnePlayerTurn(Player &player){

}