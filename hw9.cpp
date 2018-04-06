//Sabeel Kazi CS211 - Assignment 7
//Fancy eight queens printing problem
#include<iostream>
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
  //print solutions numbers
  static int solutions = 0;
  solutions++;
  cout << endl << "Solution #" << solutions << endl ;

  int i,j,k,l;
  typedef wchar_t box[5][7];
  box bb,wb,wq,bq,*board[8][8];

  //fill in bb=black box, wb=whitebox,wq=whitequeen and bq=blackqueen
  for(i=0;i<5;i++){
    for( j=0;j<7;j++){
      wb[i][j]=' ';
      bq[i][j]=' ';
      bb[i][j]=wchar_t(219);// L'\u2588'
      wq[i][j]=wchar_t(219);// L'\u2588'
    }
  }

  //Manually design the white queen and black queen box
  bq[1][1] = wchar_t(219);    wq[1][1] = ' ';
  bq[1][3] = wchar_t(219);    wq[1][3] = ' ';
  bq[1][5] = wchar_t(219);    wq[1][5] = ' ';
  bq[2][1] = wchar_t(219);    wq[2][1] = ' ';
  bq[2][3] = wchar_t(219);    wq[2][3] = ' ';
  bq[2][5] = wchar_t(219);    wq[2][5] = ' ';
  bq[3][1] = wchar_t(219);    wq[3][1] = ' ';
  bq[3][2] = wchar_t(219);    wq[3][2] = ' ';
  bq[3][3] = wchar_t(219);    wq[3][3] = ' ';
  bq[3][4] = wchar_t(219);    wq[3][4] = ' ';
  bq[3][5] = wchar_t(219);    wq[3][5] = ' ';

  //fill board with pointers to bb and wb in alternate positions
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      if((i+j)%2==0)
        board[i][j]=&wb;
      else
        board[i][j]=&bb;
    }
  }

  //fill board with bq and wq positions based on q array
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      if(q[i] == j){
        if((i + j) % 2 == 0)
          board[i][j] = &bq;
        else
          board[i][j]= &wq;
      }
    }
  }

  // print the board via the pointers in array board
  // first print upper border
  cout<<" ";
  for(i=0;i<7*8;i++){
    cout<<'_';
  }
  cout<<endl;

  // now print the board
  for(i=0;i<8;i++){
    for(k=0;k<5;k++){
      cout<<" "<<char(179); //print left border
      for(j=0;j<8;j++)
        for(l=0;l<7;l++)
          wcout<<wchar_t((*board[i][j])[k][l]);
      cout<<char(179)<<endl; // at end of line print bar and then newline
    }
  }

  //before exiting print lower border
  cout<<" ";
  for(i=0;i<7*8;i++){
    cout<<char(196);
  }
  cout<<endl;
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
