#include <iostream>
#include <cstdlib>
using namespace std;

#define vertices 4
#define alg 1 // 0 - DFS, 1 - BFS

bool visited[vertices];

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

void dfs(int matrix[vertices][vertices], int v1){
  visited[v1] = true;
  for(int v2=0; v2<vertices; v2++){
    if(matrix[v1][v2] && !visited[v2]){
      dfs(matrix, v2);
    }
  }
}

void bfs(int matrix[vertices][vertices], int v){
  bool forest[vertices];
  for(int i=0; i<vertices; i++)
    forest[i] = false;
  int front = v, rear = v;
  
  forest[v] = true;
  for(int k=0; k<vertices; k++){
    for(int i=0; i<vertices; i++){
      if(forest[i]){
        for(int j=0; j<vertices; j++){
          if(matrix[i][j]){
            forest[j] = true;
          }
        }
      }
    }
  }
  
  for(int i=0; i<vertices; i++){
    cout << "Node " << i << " is ";
    if(forest[i]){
      cout << "visitable." << endl;
    } else{
      cout << "non-visitable." << endl;
    }
  }
}


int main(){
  int matrix[vertices][vertices];
  int n = vertices;

  throwLine(20);
  for(int i=0;i<n;i++){
    for(int j=0; j<n; j++){
      if(i==j){
        matrix[i][j] = 0;
        continue;
      }
      cout << "Edge between vertex " << i << " and " << j << "? ";
      cin >> matrix[i][j];
    }
    visited[i] = false;
    throwLine(20);
  }
  if(!alg){ //DFS
    dfs(matrix, 0);
    
    for(int i=0; i<n; i++){
      if(visited[i] == false){
        cout << "Graph is not connected." << endl;
        return 0; 
      }
    }
    
    cout << "Graph is connected." << endl;
    return 0;
  } else { //BFS
    int source;
    cout << "Enter source: ";
    cin >> source;
    throwLine(20);
    bfs(matrix, source);
  }
  
  return 0;
}
