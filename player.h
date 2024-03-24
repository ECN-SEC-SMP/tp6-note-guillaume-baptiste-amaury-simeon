#include <iostream>
#include <list>
#include "case.h"

using namespace std;

#ifndef player_h
#define player_h

class Player{
private:
    string player_ID;
    list<case> list_properties;
    int position; 
    int wallet; 
    list<list<int>> last_moves; 
     
public:
    // constructeur

    Player(string ID, int start_money);

    //getter

    string get_player_ID();

    list<case> get_properties(); 

    int get_wallet();

    int get_position(); 

    list<list<int>> get_last_moves();

    // setter

    void add_property(case property_name); 

    void set_position(int new_position); 

    void set_wallet(int somme); 

    void add_last_move(int dice_1, int dice_2); 


    // modifier

    void money_transaction(int amount_of_money); 

    void move(int motion);

    void go_to_prison();

    int launch_dice();

    void sell_property(string property_name);

};

#endif