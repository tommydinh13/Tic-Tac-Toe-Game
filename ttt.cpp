
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

// game board
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

string name1;   // hold name of player 1
string name2;   // hold name of player 2
string p1;  // player 1 name with legend
string p2;  // player 2 name with legend

int mark;   // the position that player wants to mark off
int row,column; // row and column number of the board
char turn = 'X';    // x always starts
bool draw = false;  // check if draw

// show the current state of board
void displayBoard(){

    cout << "\nLEGEND: \n";
    cout<< p1 << "\n";
    cout<< p2 << "\n";

    // standard tic tac toe board
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
}

// function that allows player to make move on their turn
void playerTurn(){
    if(turn == 'X'){
        cout<< p1 << " turn: ";
    }
    else if(turn == 'O'){
        cout<< p2 << " turn: ";
    }
    // input of players choice on the board
    cin>> mark;

    // this switch statement allows for the user mark to perform a certain block of code
    // in this case, the players choice will determine which row and column will be marked
    switch(mark){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
    }
    // if mark is not on the board
    if(mark < 1 || mark > 9){
        displayBoard();
        cout<<"Invalid Move. Please enter a new move.\n";
        playerTurn();

     // if X turn and mark is not already taken   
    }else if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';   // fill mark on board with X
        turn = 'O'; // switch to O turn

     // if O turn and mark is not already taken   
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';   // fill mark on board with O
        turn = 'X'; // switch to X turn
    }else {
        //if input position already filled
        cout<<"Box taken! Choose another box!\n";
        displayBoard();
        playerTurn();
    }
}


// check to see if game should continue or stop due to win or draw
bool gameStatus(){

    //check row/column win
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return false;
        }
    }


    //check diagonal win
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return false;
    }

    // check each box to see if filled or not
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return true;    // if all boxes are not filled, continue game
            }
        }

    }


    //  draw the game
    draw = true;
    return false;
}
// function to name players
void playerName(){
    cout<<"Please enter Player 1's name: ";
    cin >> p1;
    cout<<"Please enter Player 2's name: ";
    cin >> p2;
    name1 = p1;
    name2 = p2;

    // just adding legend to make it easier for players to remember
    // if they are x or o
    p1 += " --> [X]";
    p2 += " --> [0]";

}

int main()
{
    cout<<"Let's Play Tic Tac Toe!\n";
    playerName();   // function call to have players enter names
    while(gameStatus()){
        displayBoard();
        playerTurn();
        gameStatus();
    }
    if(turn == 'X' && draw == false){
        displayBoard();
        cout<<"Game Over! " << name2 << " wins!";
    }
    else if(turn == 'O' && draw == false){
        displayBoard();
        cout<<"Game Over! " << name1 << " wins!\n";
    }
    else
    cout<<"Draw! Haha, nobody wins :D\n";
} 