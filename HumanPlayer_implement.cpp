#include "Human_player.h"

void Human_player::Move()
{
    int column_input_temp;
    string game_piece_temp2;
    
    c.draw_board();
    
    if(turn_counter[turn_decider]==player_1_name)
    {
        game_piece="x";
        
        do{
            game_piece_temp2=game_piece;
            
        }while(c.check_bound(column_input_temp,"human",game_piece_temp2));

    }
    else if(turn_counter[turn_decider]==player_2_name)
    {
        game_piece="o";
        
        do{
            game_piece_temp2=game_piece;
            
        }while(c.check_bound(column_input_temp,"human",game_piece_temp2));
    }
    
    game_decider=c.check_game_state();
    
    if(game_decider==1)
    {
        c.draw_board();
        win();
    }
    
    else if(game_decider==2)
    {
        c.draw_board();
        tie();
    }
}

