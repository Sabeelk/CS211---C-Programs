//Sabeel Kazi CS211 - Assignment 7
//Numbers in a cross problem
/*
Comments are included where the program deviates from the original 8
queens problem. Professor Waxman said to use goto statments for the assignment.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int nums[8];
  int col = 0;
  nums[0] = 0;
  int solutions = 1;                  //keeps track of solutions
  int arr[8][4] = { {-1,-1,-1,-1},    //helper array gives adjacent boxes
                    {0,-1,-1,-1},
                    {1,-1,-1,-1},
                    {0,1,2,-1},
                    {1,2,3,-1},
                    {0,3,4,-1},
                    {3,4,5,-1},
                    {2,4,6,-1}
                  };

  //-----------------------------------

  NextColumn:
  col++;
  if(col == 8) goto Print;
  nums[col] = -1;

  //-----------------------------------

  NextNum:
  nums[col]++;
  if(nums[col] == 8) goto Backtrack;

  //checks if number was used in a previous column
  for(int i = 0; i < col; i++){
    if(nums[col] == nums[i]){
      goto NextNum;
    }
  }

  //checks if current column number is consecutive to an adjacent number in cross
  //disregards the helper array index where it equals -1
  for(int i = 0; i < 4; i++){
    if(((nums[arr[col][i]]) == (nums[col] + 1) ||
        (nums[arr[col][i]]) == (nums[col] - 1)) &&
        (arr[col][i]) != -1){
          goto NextNum;
    }
  }
  goto NextColumn;

  //-----------------------------------

  Backtrack:
  col--;
  if(col == -1) return 0;
  goto NextNum;

  //-----------------------------------

  Print:
  cout << "solution # " << solutions << ": ";
  for(int i = 0; i < 8; i++){
    cout << (nums[i] + 1) << " "; //add +1 so range is from 1-8 (not 0-7)
  }
  cout << endl;

  solutions++;
  goto Backtrack;
}
