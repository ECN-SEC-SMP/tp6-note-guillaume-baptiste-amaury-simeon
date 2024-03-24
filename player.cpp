#include "player.h"
#include <stdlib.h>   

//constructor
Player::Player(string ID, int start_money){
    this->player_ID = ID; 
    this->position = 0; 
    this->wallet = start_money; 
}

//getter
string Player::get_player_ID(){
    return this->player_ID; 
}

list<case> Player::get_properties(){
    return this->list_properties;
}

int Player::get_wallet(){
    return this->wallet; 
}

int Player::get_position(){
    return this->position;
}

list<list<int>> Player::get_last_moves(){
    return this->last_moves;
}

// setter
void Player::add_property(case property_name){
    this->list_properties = get_properties().push_back(property_name);
}

void Player::set_position(int new_position){
    this->position = new_position; 
}

void Player::set_wallet(int somme){
    this->wallet = somme; 
}

void Player::add_last_move(int dice_1, int dice_2){
    list<int> last_move = {dice_1, dice_2}; 
    this->last_moves = get_last_moves().push_back(last_move); 
}

// modifier

void Player::money_transaction(int amount_of_money){
    this->wallet = get_wallet() + amount_of_money; 
}

void Player::move(int motion){
    this->position = get_position() + motion; 
}

void Player::go_to_prison(){
    this->position = 10; 
}

int Player::launch_dice(){
    int dice_1 = rand() % 6 + 1; 
    int dice_2 = rand() % 6 + 1; 
    add_last_move(dice_1, dice_2); 
    return dice_1 + dice_2;  
}

void Player::sell_property(string property_name){
    list<case> list_properties = get_properties(); 
    for (int i = 0; i = size(list_properties); i += 1){
        if (property_name = get_name(list_properties[i])){
            list_properties.erase(i);
        }
    }
}