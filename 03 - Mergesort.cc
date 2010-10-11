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

int* merge(int *left, int* right, int low, int mid, int high, int *result) {
  int leftcount = 0, rightcount = 0;
  int leftlength = mid - low;
  int rightlength = high-mid;
  int resultcount = low;
  
  while(leftlength > 0 && rightlength > 0) {
    if(left[leftcount] <= right[rightcount]) {
      result[resultcount] = left[leftcount++];
      resultcount++;
      leftlength--;
    } else {
      result[resultcount] = right[rightcount++];
      resultcount++;
      rightlength--;
    }
  }
  
  if(leftlength > 0) {
    for(int i=0; i<leftlength; i++){
      result[resultcount] = left[leftcount];
      leftcount++;
      resultcount++;
    } 
  }
  else if(rightlength > 0){
    for(int i=0; i<rightlength; i++){
      result[resultcount] = right[rightcount];
      rightcount++;
      resultcount++;
    }
  }
}

int* mergeSort(int *arr, int low, int high) {
  int mid = (high-low) == 2 ? low + 1 : (int) ((low + high) / 2) + 1;
  
  int left[mid - low], right[high - mid];
  int rightcount = 0;
  
  if((high - low)  == 1) {
    return arr;
  }
  
  for(int i=0; i<(high-low); i++) {
    if(i<mid){
      left[i] = arr[i];
    }
    else {
      right[rightcount] = arr[i];
      rightcount++;
    }
  }
  
  mergeSort(left,0,mid);
  mergeSort(right,0,high-mid);
  merge(left,right, low, mid, high, arr);  
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
   
   
   mergeSort(arr,0,n);
   
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