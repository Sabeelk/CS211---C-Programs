//Sabeel Kazi CS211 - Assignment 8
//Stable Marriage problems using 8 queens backtracking
#include <iostream>
#include <cmath>
using namespace std;

//only check array needs to be changed (& some array parameters)
// check will have access to the preference arrays
bool check(int q[], int c){
  int mp[3][3] = {{0, 2, 1},
                  {0, 2, 1},
                  {1, 2, 0}
                };
  int wp[3][3] = {{2, 1, 0},
                  {0, 1, 2},
                  {2, 0, 1}
                };
  //Statements checking instability matching
  for(int i = 0; i < c; i++){
    if(q[i] == q[c]) return false;
    if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
    if(mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
  }
  return true;  //passed all instabilitiy tests
}

void backtrack(int& c){
  c--;
  if(c == -1) exit(1);
}

void print(int q[]){
  static int solutions = 0;
  solutions++;
  cout << "Solution #" << solutions << ": " ;
  for(int i = 0; i < 3; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

int main(){
  //board setup sections
  int queens[3];
  queens[0] = 0;
  int col = 0;
  bool from_backtrack = false;

  //filled based on provided template
  while(1){
    while(col < 3){
      if(!from_backtrack){
        queens[col] = -1;
      }
      from_backtrack = true;
      while(queens[col] < 3){
        queens[col]++;
        if(queens[col] == 3){
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
