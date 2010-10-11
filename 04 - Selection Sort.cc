#include <iostream>
#include <cstdlib>
using namespace std;

#define random true
#define nElements 10000
#define output false

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

void swap2(int &a, int &b){
   int temp;
   temp = a;
   a = b;
   b = temp;
}


void selectionSort(int *arr, int size){
  for(int i=0; i<size; i++){
    int smallest = i;
    for(int j=i+1;j<size;j++){
      if(arr[j] < arr[smallest]){
        smallest = j;
      }
    }
    if(arr[i]>arr[smallest]){
      swap2(arr[i],arr[smallest]);
    }
  }
}


int main(){
   
   int arr[nElements+1];
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
   
   if(output){
    throwLine(50);
    cout << "Elements\n";
    throwLine(50);
    for(int i=0;i<n;i++){
       cout << arr[i] << " ";
    }
  }
   
   
   selectionSort(arr,n);
   
   if(output) {
    cout << endl;
    throwLine(50);
    cout << "Sorted Elements\n";
    throwLine(50);
    for(int i=0;i<n;i++){
       cout << arr[i] << " ";
    }   
    cout << endl;
   }
   return 0;
   
   
}