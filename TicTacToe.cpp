#include <iostream>

using namespace std;
/*
  Program: A two player TicTacToe game
  Author: Dieter Voegels
  Date: 9/29
 */
//initialize functions
void printBoard(char board[3][3]);
bool checkWin(char player, char board[3][3]);
bool checkTie(char board[3][3]);

//constructor
int main(){
  //initialize variables
  char board[3][3];
  char X_MOVE = 'X';
  char O_MOVE = 'O';
  char move = X_MOVE;
  bool playAgain = true;
  int in[2];
  char player = 'X';
  char playAgainInput;
  bool enterAgain = true;
  int xWins = 0;
  int oWins = 0;
  //print out initial text and print the board
  cout << "Lets play tic tac toe!" << endl << "This is a two player game, player one will be X and player 2 will be O." << endl << "Player one goes first." << endl;
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      board[row][column] = ' ';
    }
  }
  printBoard(board);
  //play again loop
  while (playAgain){
    //if they enter an invalid number, ask them to repeat
    while(enterAgain){
      cout << "Enter in row number" << endl;
      cin >> in[0];
      cout << "enter in column" << endl;
      cin >> in[1];
      if(in[0] > 3 || in[1] > 3){
	cout << "enter in a row or a column 1-3" << endl;
      }
      else{
	enterAgain = false;
      }
    }
    enterAgain = true;
    //add the an X or O to the board if it is legal
    if (board[in[0]-1][in[1]-1] == 'X' || board[in[0]-1][in[1]-1] == 'O'){
      cout << "ERROR: Enter in a coordinate that is not already occupied" << endl;
    }
    else{
      board[in[0]-1][in[1]-1] = move;
      printBoard(board);
      //check win
      if(checkWin(player, board)){
	if (player == 'X'){
	  xWins++;
	}
	else{
	  oWins++;
	}
	//print out score and play again question
	cout << player << " Won!" << endl;
	cout << "X wins: " << xWins << endl;
	cout << "O wins: " << oWins << endl;
	cout << "Do you want to play again?Y/N" << endl;
	cin >> playAgainInput;
	//if Y play again if N dont play agin
	if(playAgainInput == 'Y' || playAgainInput == 'y'){
	  playAgain = true;
	  //print an empty board
	  for(int row = 0; row < 3; row++){
	    for(int column = 0; column < 3; column++){
	      board[row][column] = ' ';
	    }
	  }
	  printBoard(board);
	}
	else if (playAgainInput == 'N' || playAgainInput == 'n'){
	  playAgain = false;
	}
	else{
	  cout << "Enter in a Y or N for yes or no" << endl;
	}
      }
      //check tie
      else if (checkTie(board)){
	//print out tie and score and play again question
	cout << "Tie!" << endl;
	cout << "X wins: " << xWins << endl;
	cout << "O wins: " << oWins << endl;
	cout << "Do you want to play again?Y/N" << endl;
	cin >> playAgainInput;
	if (playAgainInput == 'Y' || playAgainInput == 'y'){
	  //print out an empty board
	  for(int row = 0; row < 3; row++){
	    for(int column = 0; column < 3; column++){
	      board[row][column] = ' ';
	    }
	  }
	  printBoard(board);
	}
	else if (playAgainInput == 'N' || playAgainInput == 'n'){
	  playAgain = false;
	}
      }
      //if no win or tie, then change the player
      else if(move == X_MOVE){
	move = O_MOVE;
	player = O_MOVE; 
      }
      else{
	move = X_MOVE;
	player = X_MOVE;
      }
    }
  }
}

//print out the board function
void printBoard(char board[3][3]){
  int rowNumber = 1;
  cout << " 123" << endl;
  for(int row = 0; row < 3; row++){
    cout << rowNumber++;
    for(int column = 0; column < 3; column++){
      cout << board[row][column];
    }
    cout << endl;
  }
}

//check win function
bool checkWin(char player, char board[3][3]){
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  else if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  else if(board[2][0] == player && board[1][1] == player && board[0][2] == player){
    return true;
  }
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return true;
  }
  else if(board[0][0] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player){
    return true;
  }
  else if(board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  else if (board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return true;
  }
  return false;
}

//check tie function
bool checkTie(char board[3][3]){
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == ' '){
	return false;
      }
    }
  }
  return true;
}
