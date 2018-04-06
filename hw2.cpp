//Kazi_Sabeel_211_HW2
#include<iostream>
using namespace std;

bool equivalent(int a[], int b[], int n){
  bool result = true;

  //checks the first n - 4 digits of the array
  for(int i = 0; i < n ; i++){
    if(i <= n - 4 && a[i] != b[i+3]){
      result = false;
    }
  }
  //checks the last 3 digits of the array1 to first 3 digits of array2
  for(int i = 0; i < 3; i++){
    if(b[i] != a[i+5]){
      result = false;
    }
  }
  return result;
}

int main(){
  int length = 5;
  //using 8 length array as an example
  //should return true
  int arr1[8] = {1,2,3,4,5,6,7,8};
  int arr2[8] = {6,7,8,1,2,3,4,5};

  //arr4[0] is not 6, so should return false
  int arr3[8] = {1,2,3,4,5,6,7,8};
  int arr4[8] = {4,7,8,1,2,3,4,5};

  //example of a correctly shifted array, returns true
  cout << equivalent(arr1, arr2, 8) << endl;

   //example of an incorrectly shifted array, returns false
  cout << equivalent(arr3, arr4, 8) << endl;
}
