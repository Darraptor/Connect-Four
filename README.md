# Connect-Four

I implemented a Connect Four game for my Computing III project illustrating the basic concepts of object orientation. When the user starts 
the progarm, they will be given the options to either play against their friend or cpu. There is also an option to look at the credits. If 
the user decides to play against someone, the board will be generated and the user has to input 0-6 inclusively to place a piece a board.
If they input any other input then the program will tell them its invalid and try to make them input 0-6. Just like a regular connect four game,
the program will end when either player gets four in a row or if no one wins after 42 turns which results in a tie.

# Classes

I created the following classes for this project:
```
1. Connect4
2. Player
3. Human_player
4. Cpu_player
```

The Connect4 class deals with making the game in terms of creating the board, checking if someone has won the game, and whether or not the move is a legal one done by the user.

Player is a parent class of Human_player and Cpu_player. Player class deals with the players making their moves and declaring whether or not the player has won. The reason I made Player a parent class is because the human player and cpu player don't move the same way which is which I had made my move function virtual in my player class. The computer makes his moves randomly within the parameters of the board which is why I don't need to check whether or not his moves are valid on the board as opposed to the human player where somemone might accidently make an invalid move. Someday I want to improve on the cpu moves by using a binary search tree to calculate the best value move for the computer to make.


To have a visual understanding of the relations of the classes please refer to the new_connect_4_umldiagram.png file.


# Sample Code

I created the connect four board by using a vector in a vector.
```vector<vector<string>> board;```

I initalized each spot on the board with an empty space that will later hold a game piece of either 'x' or 'o'. I had defined vertical
and horizontal row as a 6X7 board but if someone wanted to change the dimensions of the board for a more intense challenge then they can just redefine the vertical and horizontal parameters inside the Connect4 class.
```
for (int i=0;i<vertical_row; i++){
        vector<string> row;
        for (int j=0;j<horizontal_row; j++)
            row.push_back(" ");
        board.push_back(row);
    }
```

The following lines of code check whether or not a player has 4 in a row vertically, horizontally, or diagonally:
```

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

```


# Start up Menu

![screen shot 2017-05-06 at 10 13 07 am](https://cloud.githubusercontent.com/assets/18603999/25773069/163d0ac4-3245-11e7-9274-bca8baa653d7.png)


# Example Game Output

![screen shot 2017-05-06 at 10 17 49 am](https://cloud.githubusercontent.com/assets/18603999/25773085/504f18a6-3245-11e7-8cd7-30401cbff867.png)


