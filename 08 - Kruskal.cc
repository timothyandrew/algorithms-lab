#include <iostream>
#include <cstdlib>
using namespace std;

#define vertices 4

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

void kruskal(int matrix[vertices][vertices]){
  int parent[vertices];
  for(int i=0; i<vertices; i++){
    parent[i] = i;
  }
  
  int count = 0;
  
  while(count < vertices-1){
    int min=10000, min_i, min_j;
    for(int i=0; i<vertices; i++){
      for(int j=0; j<vertices; j++){
        if(matrix[i][j] < min && parent[i] != parent[j]){
          min = matrix[i][j];
          min_i = i;
          min_j = j;
        }
      }
    }
    
    if(parent[min_i] != parent[min_j]){
      cout << "|  " << min_i+1 << " <------> " << min_j+1 << "    |" << endl;
      count++;
      parent[min_j] = min_i;
    }
  }
  throwLine(20);
}




int main(){
  int matrix[vertices][vertices];
  int n = vertices;

  throwLine(20);
  for(int i=0;i<n;i++){
    for(int j=0; j<n; j++){
      if(i==j){
        matrix[i][j] = 1;
        continue;
      }
      cout << "Length of edge between vertex " << i+1 << " and " << j+1 << "? ";
      cin >> matrix[i][j];
    }
    throwLine(20);
  }
  
  kruskal(matrix);
  
  
   
   
}
