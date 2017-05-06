#include "Cpu_player.h"

void Cpu_player::Move()
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
    
    
    else if(turn_counter[turn_decider]==cpu)//this is where the computer calculates his moves
    {
        game_piece="o";
        
        do{
            
            if(first_turn==2 && turn_counter[turn_decider]==cpu)
            {
                first_turn++;
                column_input_temp=3;
            }
        
            else
                column_input_temp=rand()%7;//randomly chooses a move for the cpu
            
            game_piece_temp2=game_piece;
        }
        while(c.check_bound(column_input_temp,"cpu",game_piece_temp2));//this loop will end if the cpu can place the piece in that position
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