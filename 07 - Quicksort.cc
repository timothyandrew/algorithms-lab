#include <iostream>
#include <cstdlib>
using namespace std;

#define random true
#define nElements 100000
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


void quickSort(int *arr, int low, int high){
     int pivot = arr[(high+low)/2];
     int i = low;
     int j=high;
     
     while(i<=j) {
        while(arr[i]< pivot)
          i++;
        while(arr[j] > pivot)
          j--;
        if(i <= j) {
          swap2(arr[i], arr[j]);
          i++;
          j--;
        }
      }
        if(low < j)
          quickSort(arr, low,j);
        if(i < high)
          quickSort(arr, i,high);  
     
}


int main(){
   
   int arr[500000];
   int n = nElements;
      
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
  
   quickSort(arr,0,n-1);
   
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