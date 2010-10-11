#include "iostream"
#include <cstdlib>
using namespace std;

#define random true
#define keyElement 937
#define nElements 1000000
#define type 1 //0 - Linear, 1 - Binary
#define lowLimit 50
#define output false

void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

void linearSearch(int arr[], int position, int size, int key){
   if(arr[position]==key){
      cout << "Element Found.\n";
      exit(1);
   }
   if(position<size){
      linearSearch(arr,position+1,size,key);
   }
}

void binarySearch(int arr[], int high, int low, int key){
   
   int mid = (int) (high+low)/2;

   if(arr[mid] == key){
      cout << "Element Found.\n";
      exit(1);
   }
   else if(high-low == 1){
      cout << "Element not Found.\n";
      exit(1);
   }
   else if(key < arr[mid]){
      binarySearch(arr,mid,low,key);
   }
   else if(key > arr[mid]){
      binarySearch(arr,high,mid,key);
   }
}


int main(){
   
   int arr[nElements];
   int key = keyElement;
   int n;
      
   if(!random){
      throwLine(20);
      cout << "Enter how many elements?";
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
      if(!type){ //Linear Search
         for(int i=0;i<n;i++){
            arr[i] = rand()%10000;
         }
      }
      else{ // Binary Search - Ordered List
         arr[0] = lowLimit;
         int count = arr[0];
         for(int i=0;i<n;i++){
            arr[i] = count++;
         }
      }
   }
   
   if(output){
    cout << "The List is: ";
    for(int i=0;i<n;i++){
       cout << arr[i] << " ";
    }
    cout << endl << "The Key is: " << key << endl;
   }
   
   if(!type){ //Linear Search
      linearSearch(arr,0,n,key);
      cout << "Element Not Found\n";
   }
   else if(type){ //Binary Search
      binarySearch(arr,n,0,key);
      cout << "Element Not Found.\n";
   }
   
}