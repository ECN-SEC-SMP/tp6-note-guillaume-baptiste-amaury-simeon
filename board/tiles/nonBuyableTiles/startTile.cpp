#include "startTile.hpp"

StartTile::StartTile():Tile(tileName[0]) {}

void StartTile::runTileAction(Player* player){
    player->addMoney(20000); // the player gets 20k from the bank
}