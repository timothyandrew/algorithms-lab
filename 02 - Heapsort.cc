#include "iostream"
#include <cstdlib>
using namespace std;

#define random false
#define nElements 1000000

void throwLine(int n){
  for(int i=0;i<n;i++){
    cout << "-";
  }
  cout << endl;
}

void heapify(int*,int,int);
void buildheap(int*,int);
void heapSort(int*,int);

void swap2(int &a, int &b){
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void heapify(int *z, int n, int k){
   //*arr in format arr[1,2......n]

  int m = k; 

  const int l = (k<<1);  // k*2
  if ( (l <= n) && (z[l] > z[k]) )  m = l; 

  const int r = (k<<1) + 1; 
  if ( (r <= n) && (z[r] > z[m]) )  m = r;

  if (m != k) {
    swap2(z[k], z[m]);
    heapify(z, n, m);
  } 

}

void build_heap(int *x, int n){
  int *z = x - 1;   
  int j = (n>>1); // Elements after n/2 are all leaf nodes
  while ( j > 0 ) {
    heapify(z, n, j);
    --j;
  }
}

void heapSort(int *x, int n){    
  build_heap(x, n);
  int *p = x - 1;
  int k=n;
  while(k>1){
    k = n;
    swap2(p[1], p[k]);
    --n;                
    heapify(p, n, 1);   
  }
}

int main(){

  int arr[nElements];
  int n;

  if(!random){
    throwLine(20);
    cout << "Enter how many elements? ";
    cin >> n;

    throwLine(20);

    for(int i=0;i<n;i++){
      cout << "Enter element #" << i+1 << ": ";
      cin >> arr[i];
    }
    throwLine(20);
  }
  else{
    n = nElements;
    srand(rand()%1250);
    for(int i=0;i<n;i++){
      arr[i] = rand()%10000;
    }
  }

  cout << "The elements are: ";
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }


  heapSort(arr,n);

  cout << "\nThe sorted elements are: ";
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }

  cout << endl;
  return 0;


}