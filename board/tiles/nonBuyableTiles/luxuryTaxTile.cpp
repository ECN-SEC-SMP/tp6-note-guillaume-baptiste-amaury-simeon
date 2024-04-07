#include "luxuryTaxTile.hpp"

LuxuryTaxTile::LuxuryTaxTile():Tile(tileName[38]) {}

void LuxuryTaxTile::runTileAction(Player* player){
    player->removeMoney(10000); // the player pays 10k to the bank
}