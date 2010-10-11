#include <iostream>
#include <cstdlib>
using namespace std;

#define nElements 4
#define output true
#define cap 5

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

inline int max(int a, int b){
  return a > b ? a : b;
}

int knapSack(int nItems, int maxWeight, int *weights, int *values){
  int arr[nItems+1][maxWeight+1];
  
  for(int i=0; i<=nItems; i++){
    for(int j=0; j<=maxWeight; j++){
      if(i==0 || j==0){
        arr[i][j] = 0;
      } else if(weights[i] > j){
        arr[i][j] = arr[i-1][j];
      } else {
        arr[i][j] = max(arr[i-1][j], arr[i-1][j-weights[i]] + values[i]);
      }
    }
  }
  
  // Print Table
  /* 
  for(int i=0;i<=nItems;i++){
    for(int j=0;j<=maxWeight;j++){
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  } */
  
  
  return arr[nItems][maxWeight];
  
}

int main(){
   int n = nElements;
   
   int weights[n+1];
   int values[n+1];
   
    for(int i=1;i<=n;i++){
      throwLine(20);
      cout << "Element #" << i << endl;
      cout << " > Weight? ";
      cin >> weights[i];
      cout << " > Value? ";
      cin >> values[i];
    }
    throwLine(20);

   
   
   if(output){
    throwLine(50);
    cout << "Items\n";
    throwLine(50);
    for(int i=1;i<=n;i++){
       cout << "Element #" << i << " - Value: " << values[i] << " - Weight: " << weights[i] << endl;
    }
    cout << endl;
  }
   
   
   cout << "The highest value that can be placed in the knapsack is: " << knapSack(n,cap,weights,values) << endl;
  
   return 0;
   
   
}