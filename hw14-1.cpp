//Sabeel Kazi CS211 - Assignment 14-1
//Shortest path problem using recursion
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
  
int cost(int i, int j, int memo[5][6]){ // i is the row, j is the column

  //base case
  //made the base case column -1, so it is easier to use the memo later to print the path
  if(j==-1)
    return 0;
  
  //return min if it has been stored already
  if(memo[i][j] != 0)
    return memo[i][j];
  
  //recursive calls: left, down, up
  int left = weight[i][j] + cost(i, j-1, memo);
  int down = weight[i][j] + cost((i+1)%5, j-1, memo);
  int up;
  if(i-1>=0) up = weight[i][j] + cost(i-1, j-1, memo);
  else up = weight[i][j] + cost(rows-1, j-1, memo);

  //sort to find the lowest weight, assign it to min variable
  int min = left;
  if (up < min)
    min = up;
  if(down < min)
    min = down;
  
  //set the memoization array to the lowest;
  return memo[i][j] = min;
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
  
  // get the shortest path out of each cell on the right
  for(int i=0; i<rows; i++)
    ex[i]=cost(i,cols-1,memo);

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
  cout << index;              //recurive path function will not print right cell
  
  return 0;
} 

