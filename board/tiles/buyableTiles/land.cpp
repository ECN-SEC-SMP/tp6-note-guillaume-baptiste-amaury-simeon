#pragma once

#include <string>

#include "land.hpp"

// Constructors
    Land::Land(string name, int price, Color color, int mortgagePrice):BuyableTile(name, price, mortgagePrice), _color(color) {}
    Land::Land(string name, int price, Color color, int mortgagePrice, Player *player):BuyableTile(name, price, mortgagePrice, player), _color(color) {}

// Getters
    Color Land::getColor() {return _color;}
    int Land::getHouses() {return _houses;}
    bool Land::hasHotel() { return _hotel;}

// Setters
    void Land::setColor(Color color) {_color = color;}
    void Land::setHouses(int houses) {_houses = houses;}
    void Land::setHotel(bool hotel) { _hotel = hotel;}

// Methods

// Should remove a house from the board count

    void Land::addOneHouse() {
    // Récupérer l'instance de la classe Board pour accéder aux informations sur les maisons
    Board boardInstance;

    // Récupérer le nombre actuel de maisons sur ce terrain
    int currentHouses = boardInstance.getAvailableHouses();

    // Vérifier si le joueur a un monopole de couleur et si la construction est uniforme
    if (boardInstance.hasMonopoly(_color) && boardInstance.isUniformConstruction(_color, _houses + 1)) {
        // Ajouter une maison sur le terrain
        _houses++;
        // Mettre à jour le nombre de maisons sur le plateau de jeu
        boardInstance.setAvailableHouses(currentHouses - 1);
    }
}

void Land::addOneHotel() {
    // Récupérer l'instance de la classe Board pour accéder aux informations sur les hôtels
    Board boardInstance;

    // Récupérer le nombre actuel d'hôtels sur ce terrain
    int currentHotels = boardInstance.getAvailableHotels();

    // Vérifier si le joueur a un monopole de couleur et s'il a suffisamment de maisons pour construire un hôtel
    if (boardInstance.hasMonopoly(_color) && boardInstance.hasEnoughHousesForHotel(_color)) {
        // Vérifier s'il n'y a pas déjà un hôtel sur le terrain
        if (!_hotel) {
            // Ajouter un hôtel sur le terrain
            _hotel = true;
            // Mettre à jour le nombre d'hôtels sur le plateau de jeu
            boardInstance.setAvailableHotels(currentHotels - 1);
        }
    }
}

    void Board::runTileAction(Player *player) {
    // Récupérer le joueur actuel
    Player &currentPlayer = *player;

    // Obtenir le nom de la case sur laquelle le joueur est tombé
    string tileName = currentPlayer.getCurrentTile()->getName();

    // Trouver la tuile correspondante dans le vecteur de tuiles
    Tile *currentTile = nullptr;
    for (auto &tile : _tiles) {
        if (tile.getName() == tileName) {
            currentTile = &tile;
            break;
        }
    }

    // Si la tuile n'est pas trouvée, une erreur se produite
    if (currentTile == nullptr) {
        cout << "Erreur : Tuile non trouvée." << endl;
        return;
    }

    // Vérifier si la case est disponible à l'achat
    if (!currentTile->isOwned()) {
        // Proposer au joueur d'acheter la case
        if (currentPlayer.wantsToBuy(currentTile->getName(), currentTile->getPrice())) {
            // Acheter la case
            currentTile->setOwner(&currentPlayer);
            currentPlayer.pay(currentTile->getPrice());
            return;
        } else {
            // Lancer une enchère si le joueur ne veut pas acheter la case
            runAuction(currentPlayer);
            return;
        }
    }

    // Si la case est déjà possédée
Player *owner = currentTile->getOwner();
if (owner == &currentPlayer) {
    // Si le joueur est le propriétaire, il ne se passe rien
    // Le joueur peut seulement ajouter des maisons ou un hôtel selon les règles spécifiées

    // Vérifier si la case est une propriété achetable et que le joueur a un monopole de couleur
    BuyableTile *buyableTile = dynamic_cast<BuyableTile*>(currentTile);
    if (buyableTile != nullptr && Board::hasMonopoly(buyableTile->getColor())) {
        // Proposer au joueur d'ajouter une maison ou un hôtel
        if (currentPlayer.wantsToBuild()) {
            if (buyableTile->hasHotel()) {
                // Si un hôtel est déjà construit, proposer d'ajouter une maison
                buyableTile->addOneHouse();
            } else {
                // Sinon, proposer d'ajouter une maison ou un hôtel, en vérifiant s'il n'y a pas déjà un hôtel
                if (!buyableTile->hasHotel() && currentTile->getHouses() < 4) {
                    buyableTile->addOneHouse();
                } else if (!buyableTile->hasHotel() && currentTile->getHouses() >= 4) {
                    if (currentPlayer.wantsToBuildHotel() && Board::hasEnoughHousesForHotel(buyableTile->getColor())) {
                        buyableTile->addOneHotel();
                    } else {
                        cout << "Vous ne pouvez pas construire d'hôtel sur ce terrain pour le moment." << endl;
                    }
                } else {
                    cout << "Vous ne pouvez pas construire plus d'un hôtel sur ce terrain." << endl;
                }
            }
        }
        } else {
            // Si le joueur n'a pas encore un monopole de couleur, informer le joueur
            cout << "Vous devez posséder tous les terrains de la même couleur pour construire des maisons et des hôtels." << endl;
        }
    } else {
        // Si la case appartient à quelqu'un d'autre, payer le loyer au propriétaire
        int rent = currentTile->getRent();
        currentPlayer.payRent(rent, owner);
    }
}
