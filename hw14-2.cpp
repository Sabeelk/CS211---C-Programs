//Sabeel Kazi CS211 - Assignment 14-2
//Shortest path problem using iterative method
#include<iostream>
using namespace std;

const int rows = 5;
const int cols = 6;
const int weight[rows][cols]={
                {3,4,1,2,8,6},
                {6,1,8,2,7,4},
                {5,9,3,9,9,5},
                {8,4,1,3,2,6},
                {3,7,2,8,6,4}};

//cost function now works iteratively
void cost(int memo[rows][cols]){
  //assing the first column of weight to memo array
  for(int i=0; i<rows; i++)
    memo[i][0] = weight[i][0];
  
  /*see the previous up left and down element at each 
  point in the memo array beginning from column 1. Find the min
  and add it to the value in weight and set the sum in the memo array.
  For loops are iterating down the column. 
  */
  for(int i=1; i<cols; i++){
    for(int j=0; j<rows; j++){
      int up = memo[j-1>=0?j-1:rows-1][i-1];
      int left = memo[j][i-1];
      int down = memo[(j+1)%5][i-1];
      
      int min = left;
      if (up < min)
        min = up;
      if(down < min)
        min = down;
      
      memo[j][i] = weight[j][i] + min;
    }
  }
}

//path function will trace the lowest path using recursion
void path(int i, int j, int memo[5][6]){
    //base case
    if(j==0)
      return;
    
    //check the values to left, up, down in memo array
    int left = memo[i][j-1];
    int down = memo[(i+1)%5][j-1];
    int up;
    if(i-1>=0) up = memo[i-1][j-1];
    else up = memo[rows-1][j-1];
    
    //find the minimum of values and set i
    int min = left; 
    if (up < min){
      min = up;
      if(i-1>=0) i = i-1;
      else i = rows-1;
    }
    if(down < min){
      min = down;
      i = (i+1)%5;
    }
    
    //recursive call
    path(i, j-1, memo);
    
    //print the row
    cout << i << " ";
}


int main(){
  int memo[rows][cols] ={0};
  int ex[rows];
  cost(memo);
  
  // get the shortest path out of each cell on the right
  for(int i=0; i<rows; i++)
    ex[i]=memo[i][5];

  // now find the smallest of them
  int exMin= ex[0];
  int index;
  for(int i=0; i<rows; i++){
    if(ex[i]<exMin){
      exMin = ex[i];
      index = i;
    }
  }
  
  cout<<"The shortest path is of length "<< exMin <<endl; 
  cout<<"The sequence of rows for the shortest path is: ";
  path(index, cols-1, memo);  //call to path function
  cout << index;              //recurive path function will not print right most cell

  return 0;
} 
