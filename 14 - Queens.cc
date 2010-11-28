#include <iostream>
#include <cmath>
using namespace std;

#define num 8

int columns[num];


bool legal(int k){
  if(k==0)
    return true;
  
  for(int i=0; i<k; i++){
    if(columns[k] == columns[i]) //Horizontal
      return false;
    
    if(abs(columns[k] - columns[i]) == abs(k - i)) // Diagonal
      return false;
  }
  
  return true;
  
}

void print_board(){
  for(int i=0; i<num;i++){
    for(int j=0; j<num; j++){
      if(i == columns[j]){
        cout << " O ";
      } else{
        cout << " x ";
      }
    }
    cout << endl;
  }
  cout << "-----------------" << endl;
}

void backtrack(int &currentCol, int n, int &count){
  if(currentCol == 0){
    cout << "Failed.";
    exit(1);
  }
  columns[currentCol] = 0;
  currentCol--;
  if(columns[currentCol] == n-1){
    backtrack(currentCol,n, count);
  } else{
    columns[currentCol]++;
    count++;
  }
}

void queen(int n){
  for(int i=0; i<n; i++)
    columns[i] = 0;
    
  int currentCol = 0;
  int count = 0;
  while(columns[0] < n-1){
    if(currentCol == n-1){
      //cout << legal(currentCol) << endl;
      if(legal(currentCol)){
        cout << "Solution found: " << endl;
        print_board();
        cout << endl;
      }
    }
    
    if(!legal(currentCol)){
      if(columns[currentCol] < n-1){
        columns[currentCol]++;
        count++;
      } else{
        if(currentCol==0){
          cout << "Failed.";
          exit(1);
        } else{
          //cout << "hello";
          backtrack(currentCol, n, count);
        }
      }
    } else{ //Legal
      currentCol++;
    }
    //print_board();
    //exit(0);
  }
}

int main(){
  queen(num);
  return 0;
}