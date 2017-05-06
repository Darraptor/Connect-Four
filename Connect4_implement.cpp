#include "Player.h"

void Connect4::create_board()
{
    //If someone has already won/tied then the board will restart if they want to play again
    if(game_time_tracker>0)
    {
        board.clear();
        
        //Starts back at turn 1
        game_time_tracker=0;
    }
    
    //Creates a typical 7 by 6 connect four board
    for (int i=0;i<vertical_row; i++){
        vector<string> row;
        
        for (int j=0;j<horizontal_row; j++)
            row.push_back(" ");
        board.push_back(row);
    }
}

//Checks to see if the input can be placed
int Connect4::check_bound(int j,string name_holder,string k){
     while(1) {
        
         //This is here so the cpu doesnt have to reinput their choice
         if(name_holder=="human")
            cin>>choice;
         
         //Cpu already has an input and we know its valid so we only need to check if its in bound
         else
            break;
     
        if(choice=="0") {
            j=0;
            break;
        }
        else if(choice=="1"){
            j=1;
            break;
        }
        
        else if(choice=="2") {
            j=2;
            break;
        }

        else if(choice=="3")
        {
            j=3;
            break;
        }
         
        else if(choice=="4")
        {
            j=4;
            break;
        }
         
         else if(choice=="5")
        {
            j=5;
            break;
        }
         
        else if(choice=="6")
        {
            j=6;
            break;
        }
        else
        {
            //If the human player doesn't input a range 0-6 then the program will make you redo it
            if(name_holder=="human")
                cout<<"Invalid input. Your input must range from 0-6 "<<endl;
        }
    }

    for(int i=5;i>-1;i--)
    {
        //If the spot is free then insert the piece
        if(board[i][j]!="o" && board[i][j]!="x")
        {
            board[i][j]=k;
            return 0;
        }
        
        //If we are at the first row of the board
        else if(i==0)
        {
            //If the column is filled the program will ask you to input again
            if(board[0][j]=="o" || board[0][j]=="x")
            {
                if(name_holder=="human")
                    cout<<"Column is filled up please choose another column"<<endl;
                return 1;
            }
        }
    }
    return 1;
}

int Connect4::check_game_state()
{
    //Tracks the time
    ++game_time_tracker;
    
    //Checks for a horizontal win
    for(int i=0;i<vertical_row;i++)
        for(int j=0;j<horizontal_row-3;j++)
            if(board[i][j]!=" " && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3])
                return 1;
    
    //Checks for a vertical win
    for(int i=0;i<vertical_row-3;i++)
        for(int j=0;j<horizontal_row;j++)
            if(board[i][j] !=" " && board[i][j]==board[i+1][j] && board[i][j]==board[i+2][j] && board[i][j]==board[i+3][j])
                return 1;
    
    //Checks left diagonal for a win
    for(int i=0;i<vertical_row-3;i++)
        for(int j=0;j<horizontal_row;j++){
            if(board[i][j] !=" " && board[i][j]==board[i+1][j+1] && board[i][j]==board[i+2][j+2] && board[i][j]==board[i+3][j+3])
                    return 1;
    }
    
    //Checks left diagonal for a win
    for(int i=0;i<vertical_row-3;i++)
        for(int j=3;j<horizontal_row;j++)
            if(board[i][j] !=" " && board[i][j]==board[i+1][j-1] && board[i][j]==board[i+2][j-2] && board[i][j]==board[i+3][j-3])
            return 1;
    
    //If there no more places where you can put the pieces then its a tie
    if(game_time_tracker==42)
        return 2;
    
    //So far nobody has won/lost/tied
    return 3;
}

//Displays the board
void Connect4::draw_board()
{
    cout<<"--------------------------------"<<endl;
    
    for (int i=0;i<vertical_row; i++){
        for (int j=0;j<horizontal_row; j++)
        {
            cout<<" |";
            cout<<" "<<board[i][j];
        }
        cout<<" |";
        cout<<endl;
    }
    
    cout<<"--------------------------------"<<endl;
    
    cout<<"   0";
    cout<<"   1";
    cout<<"   2";
    cout<<"   3";
    cout<<"   4";
    cout<<"   5";
    cout<<"   6"<<endl;
}