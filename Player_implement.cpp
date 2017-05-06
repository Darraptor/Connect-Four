#include "Player.h"

void Player::set_player_name(int number)
{
    cout<<"Enter player 1's name"<<endl;
    cin>>player_1_name;
    
    //The players name get stored inside a vector which will help decide who goes first
    
    if(number==1)
    {
        cout<<"Enter player 2's name"<<endl;
        cin>>player_2_name;
        
        turn_counter.push_back(player_1_name);
        turn_counter.push_back(player_2_name);
    }
    
    else
    {
        turn_counter.push_back(player_1_name);
        turn_counter.push_back(cpu);
    }
}


string Player::getPlayerTurn()
{
    //if its the first turn then the program will randomly choose a player to go first
    if(first_turn==1)
    {
        srand(time(NULL));
        turn_decider=rand()%2;
        ++first_turn;
        return turn_counter[turn_decider];
    }
    
    //if player 1 went then player 2 will go
    else if(turn_decider==0){
        ++turn_decider;
        return turn_counter[turn_decider];
    }
    //if player 2 went then player 1 will go
    else{
        --turn_decider;
        return turn_counter[turn_decider];
    }
}

void Player::play()
{
    c.create_board();
    
    //loops end when the player doesnt wanna play anymore
    while(play_current_game)
    {
        cout<<"It's "<<getPlayerTurn()<<" turn!"<<endl;
        Move();
    }
    
    play_current_game=true;
    first_turn=1;
}

void Player::win()
{
    cout<<turn_counter[turn_decider]<<" you win!"<<endl;
    agree();
}

void Player::tie()
{
    cout<<"It's a tie between "<<player_1_name<<" and "<<player_2_name<<endl;
    agree();
}

void Player::agree()
{
    cout<<"Rematch?"<<endl;
    
    cout<<"Enter Y or y for yes, N or n for no"<<endl;
    cin>>answer;
    
    while(answer!="y" && answer!="Y" && answer!="n" && answer!="N")
    {
        cin.clear();
        cin.ignore();
        cout<<"Invalid input please try again"<<endl;
        cout<<"Enter Y or y for yes, N or n for no"<<endl;
        cin>>answer;
    }
    
    if(answer=="y"||answer=="Y"){
        //resets the connect four board
        c.create_board();
    }
    
    else
        play_current_game=false;
}
