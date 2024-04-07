#include "goToPrison.hpp"

GoToPrison::GoToPrison():Tile(tileName[30]) {}

void GoToPrison::runTileAction(Player* player){
    player->setPosition(40); // moves the player to the prison tile
}