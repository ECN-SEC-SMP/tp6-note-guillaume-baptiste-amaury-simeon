#include "taxTile.hpp"

TaxTile::TaxTile():Tile(tileName[4]) {}

void TaxTile::runTileAction(Player* player){
    player->removeMoney(20000); // the player pays 20k to the bank
}