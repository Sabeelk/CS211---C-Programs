//Sabeel Kazi CS211 - Assignment 7
//FUnction pointers as function Arguments
#include<iostream>
using namespace std;

//functions to be passed
double line(double x){
  return x;
}
double square(double x){
  return x*x;
}
double cube(double x){
  return x*x*x;
}

//integration function
typedef double (*FUNC)(double);
double integrate(FUNC f, double a, double b){
  int n = 1000;                   //n is is arbritrary and can be redefined higher for precision
  double width = (b - a) / n;     //gives width based on n subsections
  double area = 0.0;
  for(int i=0; i < n; i++){
    area += f(a + (width * i)) * width;   // adss all area(=h*w) of each subsection
  }
  return area;
}

int main(){
  cout << "The integral of f(x)=x between 1 and 5 is: "
       << integrate(line, 1, 5) << endl;
  cout << "The integral of f(x)=x^2 between 1 and 5 is: "
       << integrate(square, 1, 5) << endl;
  cout << "The integral of f(x)=x^3 between 1 and 5 is: "
       << integrate(cube, 1, 5) << endl;

  return 0;
}
