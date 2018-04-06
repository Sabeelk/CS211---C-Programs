//Sabeel Kazi CS211 - Assignment 6
//8 Queens Problem Using 1D Array w/o Goto
#include <iostream>
#include <cmath>
using namespace std;

bool check(int q[], int c){
  //row, up diag & down diag test statement
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || (c - i) == (abs)(q[c] - q[i])){
      return false;
    }
  }
  return true;
}

void backtrack(int& c){
  c--;
  if(c == -1) exit(1);
}

void print(int q[]){
  static int solutions = 0;
  solutions++;
  cout << "Solution #" << solutions << endl ;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
        if(q[i] == j) cout << "1 ";
        else cout << "0 ";
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  //board setup sections
  int queens[8];
  queens[0] = 0;
  int col = 0;
  bool from_backtrack = false;

  //filled based on provided template
  while(1){
    while(col < 8){
      if(!from_backtrack){
        queens[col] = -1;
      }
      from_backtrack = true;
      while(queens[col] < 8){
        queens[col]++;
        if(queens[col] == 8){
          from_backtrack = true;
          backtrack(col);
          break;
        }
        if(check(queens, col)){
          from_backtrack = false;
          col++;
          break;
        }
      }
    }
    print(queens);
    backtrack(col);
    from_backtrack = true;
  }
}
