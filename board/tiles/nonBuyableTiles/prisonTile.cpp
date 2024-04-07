#include "prisonTile.hpp"

PrisonTile::PrisonTile():Tile(tileName[40]) {}

void PrisonTile::runTileAction(Player* player){
    player->removeMoney(5000); // the player pays a 5k fine
}