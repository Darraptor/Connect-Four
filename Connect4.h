#ifndef Connect_four_project_Connect4_h
#define Connect_four_project_Connect4_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Connect4
{
public:
    void create_board();
    void draw_board();
    int check_game_state();
    int check_bound(int x, string name_holder,string k);
private:
    vector<vector<string>> board;
    int vertical_row=6;
    int horizontal_row=7;
    int game_time_tracker=0;
    string choice;
};

#endif

