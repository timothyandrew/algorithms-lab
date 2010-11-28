#include <iostream>
#include <cstdlib>
using namespace std;

#define vertices 6
#define edges 9
#define infinity 999999

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

struct edge{
  int v1;
  int v2;
};

bool elementInArray(edge *arr, int size, edge v){
  for(int j=0; j<size; j++){
    if((arr[j].v1 == v.v1 && arr[j].v2 == v.v2) || (arr[j].v1 == v.v2 && arr[j].v2 == v.v1)){
      return true;
    }
  }
  return false;
}


void kruskal(int matrix[vertices][vertices]){
  int parent[vertices];
  for(int i=0; i<vertices; i++){
    parent[i] = i;
  }
  
  int count = 0;
  edge selected[100];
  
  while(count < vertices-1){
    int min=infinity, min_i, min_j;
    for(int i=0; i<vertices; i++){
      for(int j=0; j<vertices; j++){
        if(matrix[i][j] < min && parent[i] != parent[j]){
          min = matrix[i][j];
          min_i = i;
          min_j = j;
        }
      }
    }
    
    edge a;
    a.v1 = min_i;
    a.v2 = min_j;
    
    if(count == 0){
      cout << "|  " << min_i << " <------> " << min_j << "    |" << endl;
      parent[min_j] = min_i;
      selected[count++] = a;
      continue;
    }
    
    edge b;
    b.v1 = 3;
    b.v2 = 5;
    
    if(parent[min_i] != parent[min_j]){
      
      if(!elementInArray(selected,count,a)){
        cout << (!elementInArray(selected,count, b));
        cout << "|  " << min_i << " <------> " << min_j << "    |" << endl;
        parent[min_j] = min_i;
        selected[count++] = a;
      }
    }
    

  }
  throwLine(20);
}

int main(){
  int matrix[vertices][vertices];
  int n = vertices, i, j, u, v, w;

	FILE *fin = fopen("dist.txt", "r");
	for (i = 0; i < vertices; i++){
		for (j = 0; j < vertices; j++){
			matrix[i][j] = infinity;
		}
	}

	for (i = 0; i < edges; ++i) {
		fscanf(fin, "%d%d%d", &u, &v, &w);
		matrix[u][v] = w;
		matrix[v][u] = w;
	}
	fclose(fin);
	
  throwLine(20);
  kruskal(matrix);  
}
