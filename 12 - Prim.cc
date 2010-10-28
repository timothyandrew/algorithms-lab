#include <iostream>
using namespace std;

/*
  Input file should be named dist.txt, and in the following format.
  The number of lines equals the number of 'edges' defined right below.
  Each line is of the form x y z, which indicates that there is a (undirected) edge between x and y, with magnitude z.
*/

#define vertices 7
#define edges 11
#define infinity 999999

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

struct edge {
  int v1;
  int v2;
  int weight;
};

bool elementInArray(int *arr, int size, int elem){
  for(int j=0; j<size; j++){
    if(arr[j] == elem){
      return true;
    }
  }
  return false;
}

void prim(edge allEdges[(2*edges)]){
  int Vnew[(2*edges)];
  for(int i=0; i<(2*edges); i++){
    Vnew[i] = -1;
  }
  int Vcount = 1, count = 0, totalWeight = 0;
  Vnew[0] = 0;
  
  while(count < vertices-1){
    int smallest = infinity;
    int rec = -1;
    for(int i=0; i<(2*edges); i++){
      if(elementInArray(Vnew,(2*edges),allEdges[i].v1) && !elementInArray(Vnew,(2*edges),allEdges[i].v2)){
        if(allEdges[i].weight <= smallest){
          rec = i;
          smallest = allEdges[i].weight;
        }
      }
    }
    if(rec > -1){
      count++;
      Vnew[Vcount++] = allEdges[rec].v2;
      cout << allEdges[rec].v1 << " <----> " << allEdges[rec].v2 << " " << endl;
      totalWeight += allEdges[rec].weight;
    } else {
      cout << "Error";
      exit(1);
    }
  }
  throwLine(12);
  cout << "Weight is " << totalWeight << "." << endl;
  throwLine(12);
}


int main(){  
  int i, j;
	int u, v, w;
  int matrix[vertices][vertices];

	FILE *fin = fopen("dist.txt", "r");
  edge allEdges[(2*edges)];
	for (i = 0; i < edges; i++) {
		fscanf(fin, "%d%d%d", &u, &v, &w);
    allEdges[i].v1 = u;
    allEdges[i].v2 = v;
    allEdges[i].weight = w;
    //cout << allEdges[i].v1 << " <----> " << allEdges[i].v2 << " " << endl; //Display original graph
    
    allEdges[i + edges].v1 = v;
    allEdges[i + edges].v2 = u;
    allEdges[i + edges].weight = w;        
	}
	fclose(fin);
	
  throwLine(12);
  prim(allEdges);
  
  return 0;
}