//Sabeel Kazi CS211 - Assignment 5
//8 Queens Problem Using Goto and 1D array
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int queens[8];
  int col = 0;
  queens[0] = 0;
  int solutions = 1;    //keeps track of solutions

  //-----------------------------------

  NextColumn:
  col++;
  if(col == 8) goto Print;
  queens[col] = -1;

  //-----------------------------------

  NextRow:
  queens[col]++;
  if(queens[col] == 8) goto Backtrack;

  //row, up , down diagonal test statement
  for(int i = 0; i < col; i++){
    if((queens[col] == queens[i]) || (col - i == (abs)(queens[col] - queens[i]))){
      goto NextRow;
    }
  }
  goto NextColumn;

  //-----------------------------------

  Backtrack:
  col--;
  if(col == -1) return 0;
  goto NextRow;

  //-----------------------------------

  Print:
  cout << "Solution #" << solutions << endl ;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
        if(queens[i] == j) cout << "1 ";
        else cout << "0 ";
    }
    cout << endl;
  }
  cout << endl;
  solutions++;
  goto Backtrack;
}
