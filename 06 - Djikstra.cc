#include <iostream>
using namespace std;

/*
  Input file should be named dist.txt, and in the following format.
  The number of lines equals the number of 'edges' defined right below.
  Each line is of the form x y z, which indicates that there is a (undirected) edge between x and y, with magnitude z.
*/

#define vertices 5
#define edges 6
#define infinity 999999
int dist[vertices];

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

int* djikstra(int matrix[vertices][vertices], int s){
  
  bool visited[vertices];
  int source = s;
  
  for(int i=0; i<vertices; i++){
    dist[i] = infinity;
    visited[i] = false;
  }
  dist[source] = 0;
  
  while(true){  
    for(int j=0; j<vertices; j++){
      if(!visited[j]){
        if(matrix[source][j] != infinity){
          if((matrix[source][j] + dist[source]) < dist[j]){
            dist[j] = matrix[source][j] + dist[source];
          }
        }
      }  
    }

    visited[source] = true;
    
    int smallest = infinity;
    for(int i=0; i<vertices; i++){
      if(!visited[i] && dist[i] < smallest){
        smallest = dist[i];
        source = i;
      }
    }
    
    if(smallest == infinity){
      return dist;
    }
  }
}


int main(){  
  int i, j;
	int u, v, w;
  int matrix[vertices][vertices], *dist, source;

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
	
  cout << "Source? (zero-based) ";
  cin >> source;
	
	
  dist = djikstra(matrix, source);
  
  throwLine(20);
  for(int i=0;i<vertices;i++){
    cout << source << " <---> " << i << "   ==   " << dist[i];
    cout << endl;
  }
  throwLine(20);
  cout << endl;
  
  return 0;
}