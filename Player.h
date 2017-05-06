#ifndef connect_four_project_Player_h
#define connect_four_project_Player_h

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Connect4.h"
using namespace std;

//Class player is abstract 
class Player{
public:
    virtual void Move()=0;
    void set_player_name(int number);
    void play();
    string getPlayerTurn();
    void win();
    void tie();
    void agree();
protected:
    vector<string> turn_counter;
    string player_1_name;
    string player_2_name;
    string cpu="CPU";
    int turn_decider;
    string game_piece;
    int first_turn=1;
    int game_decider;
    Connect4 c;
private:
    string answer;
    bool play_current_game=true;
};

#endif
