//Sabeel Kazi CS211 - Assignment 11
//N-Queens program using dynamic array
#include <iostream>
#include <cmath>
using namespace std;

//check function remains the same
bool check(int q[], int c){
  //row, up diag & down diag test statement
  for(int i = 0; i < c; i++){
    if(q[c] == q[i] || (c - i) == (abs)(q[c] - q[i])){
      return false;
    }
  }
  return true;
}

/*
backtrack now prints the solutions when c==-1
gets the n and solutions from calulate to print
*/

void backtrack(int& c, int n, int sol){
  c--;
  if(c == -1){
    cout << "There are " << sol << " solutions to the ";
    cout << n << " queens problem." << endl;
  }
}

/*
original loop has been modified into a function for each n queens problem
calculate function takes an incrementing number from function main (1 through n)
print function has been removed, printing now done in backtrack function when c==-1
new dynamic queens array is made for each function argument
queens is deleted at end of loop to free heap
most of the logic loops in the while function remian the same
*/
void calculate(int n){
  int solutions = 0;
  int* queens = new int[n];
  queens[0] = 0;
  int col = 0;
  bool from_backtrack = false;

  while(1){
    while(col < n){
      if(!from_backtrack){
        queens[col] = -1;
      }
      from_backtrack = true;
      while(queens[col] < n){
        queens[col]++;
        if(queens[col] == n){
          from_backtrack = true;
          backtrack(col, n, solutions);
          if(col == -1) {              //ends functions when all solutions found
            delete []queens;          //clears the heap from dynamic queens
            return;
          }
          break;
        }
        if(check(queens, col)){
          from_backtrack = false;
          col++;
          break;
        }
      }
    }
    solutions++;
    backtrack(col, n, solutions);
    from_backtrack = true;
    if(col == -1) {              //ends functions when all solutions found
      delete []queens;          //clears the heap from dynamic queens
      return;
    }
  }
}

/*
Main function takes user input n
iterates from 1 through n and feeds to calulate function
solution numbers are printed for each value of i in for loop (up to n)
*/
int main(){
  cout << "Please enter the number of queens";
  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    calculate(i);
  }

  return 0;
}
