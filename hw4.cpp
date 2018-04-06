//Sabeel Kazi CS211 - Assignment 4
//8 Queens Problem Using Goto

#include <iostream>
using namespace std;

int main(){
  int solution = 1;
  int board[8][8] = {0};
  int row;                               //row is not initialized
  int col = 0;
  board[0][0] = 1;                      //places the first queen

  //--------------------------------------------------------

  NextColumn:                           //goto next column
  col++;
  if(col==8) goto Print;
  row = -1;                            //will start at row[0]

  //--------------------------------------------------------

  NextRow:                            //goto next row
  row++;
  if (row == 8) goto Backtrack;       //if no queen can be placed backtrack

  //Row Test
  for(int i = 0; i < col ; i++){
    if(board[row][i] == 1) goto NextRow;
  }
  //Up Diagonal Test
  for(int i = 1; (row - i) >= 0 && (col - i) >= 0; i++){
    if(board[row-i][col-i] == 1) goto NextRow;
  }
  //Down Diagonal test
  for(int i = 1; (row + i) < 8 && (col - i) >= 0; i++){
    if(board[row+i][col-i] == 1) goto NextRow;
  }

  board[row][col] = 1;                          //place a queen
  goto NextColumn;                              //test next column

  //--------------------------------------------------------

  Backtrack:
  col--;                                        //go to previous column
  if(col == -1) return 0;                       //exit if all columns have been found
  row = 0;                                      //start from top of column

  while(board[row][col] != 1) row++;
  board[row][col] = 0;                          //remove queen
  goto NextRow;                                 //begin tests

  //--------------------------------------------------------

  Print:
  cout << "Solution #" << solution << endl;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  solution++;
  goto Backtrack;
}
