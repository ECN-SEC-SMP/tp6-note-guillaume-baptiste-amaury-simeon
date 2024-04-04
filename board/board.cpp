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
    // init tiles =======================> TODO
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
    vector<Player> playersList = getPlayers(); 
    for (int player = 0; player < playersList.size(); player++){
        Player actualPlayer = playersList[player]; 
        playOnePlayerTurn(actualPlayer); 
    } 
}

void Board::playOnePlayerTurn(Player &player){
    if (player.isInJail() == 0){
        cout << "It is now to " << player.getName() << " to play" << endl; 
        int firstDice = player.launchOneDice(); 
        int secondDice = player.launchOneDice(); 
        if (firstDice == secondDice){
            player.addDiceDouble();
        }
        else {
            player.resetDiceDoubles(); 
        }

        if (player.getDiceDoubles() == 3){
            player.setJailState(1); 
        }
        else {
            int playerPosition = player.getPosition(); 
            playerPosition = playerPosition + firstDice + secondDice; 
            player.setPosition(playerPosition); 
            vector<Tile> ListTiles = getTiles(); 
            // Tile actualTile = ListTiles[playerPosition];
            // actualTile.runTileAction(*player);
        }
    }   
}

bool Board::hasColorMonopoly(Color color) const {
    int count = count_if(_lands.begin(), _lands.end(), [color](const Land* land) {
        return land->getColor() == color && land->isOwned() && land->getOwner()->hasMonopoly(color);
    });
    return count == LANDS_PER_GROUP; 
}

bool Board::CanConstructNewHouse(Color color, int newHouses) const {
    int minHouses = MAX_HOUSES;
    int maxHouses = 0;

    for (const Land* land : _lands) {
        if (land->getColor() == color) {
            minHouses = min(minHouses, land->getHouses());
            maxHouses = max(maxHouses, land->getHouses());
        }
    }
    return (newHouses >= minHouses && newHouses <= maxHouses + 1);
}

bool Board::CanConstructHotel(Color color) const {
    int minHousesForHotel = 4;
    
    // Vérifier si chaque terrain de la même couleur a suffisamment de maisons pour construire un hôtel
    for (const Land* land : _lands) {
        if (land->getColor() == color && land->getHouses() < minHousesForHotel) {
            return false;
        }
    }
    return true;
}