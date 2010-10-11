#include <iostream>
#include <cstdlib>
using namespace std;

#define vertices 4
#define alg 1 // 1 - Warshall, 0 - Floyd

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

int min2(int a, int b) {
  if(a < b){
    return a;
  }
  return b;
}


void warshall(int matrix[vertices][vertices], int size){
  for(int k=0; k<size; k++){ 
    for(int i=0; i<size; i++){
      for(int j=0; j<size; j++){
        if((matrix[i][j] == 1) || (matrix[i][k] == 1 && matrix[k][j] == 1)){
          matrix[i][j] = 1;
        } else {
          matrix[i][j] = 0;
        }
      }
    }
  }
}

void floyd(int matrix[vertices][vertices], int size){

  for(int k=0; k<size; k++){
     for(int i=0; i<size; i++){
       for(int j=0; j<size; j++){
         matrix[i][j] = min2(matrix[i][j], matrix[i][k] + matrix[k][j]);     
       }
     }
   }
   
  cout << "Shortest Paths" << endl;
   throwLine(20);
  
    for(int i=0;i<size;i++){
      for(int j=0; j<size; j++){
        if(matrix[i][j] != -1){
          cout << " ";
        }
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
}

int main(){
  int matrix[vertices][vertices];
  int n = vertices;

  throwLine(20);
  for(int i=0;i<n;i++){
    for(int j=0; j<n; j++){
      if(alg){
        if(i==j){
          matrix[i][j] = 1;
          continue;
        }
        cout << "Edge between vertex " << i+1 << " and " << j+1 << "? ";
      } else {
        if(i==j){
          matrix[i][j] = 0;
          continue;
        }
        cout << "Length of edge between vertex " << i+1 << " and " << j+1 << "? ";
      }
      cin >> matrix[i][j];
    }
    throwLine(20);
  }
  
  if(alg){ //Warshall
   warshall(matrix, n);  
  } else { //Floyd
    floyd(matrix, n);
  }
  
  if(alg){
    cout << "Transitive closure" << endl;
   throwLine(20);
  
    for(int i=0;i<n;i++){
      for(int j=0; j<n; j++){
        if(matrix[i][j] != -1){
          cout << " ";
        }
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    } 
  }
   return 0;
   
   
}
