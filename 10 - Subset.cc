#include <iostream>
#include <cmath>
using namespace std;

/*
  Gets powerset of the array. Sums each subset. Prints matches.
  Uses the following logic to obtain powerset: http://stackoverflow.com/questions/2685501/c-next-permutation-for-combinations-or-subsets-in-powerset/2686078#2686078
*/

#define size 6
#define requiredSum 9
char a[size];


void throwLine(int n){
   for(int i=0;i<n;i++){
      cout << "-";
   }
   cout << endl;
}

char* getBinary(int number){
  int count = 0;
  
  for(int i = size-1; i >= 0; i--){
    if(number & (1<<i)) a[count] = '1';
      else a[count] = '0';
      count++;
  }
  return a;
}

int main(){
  int set[size] = {1,2,5,6,8,9};
  int subset[size];
  
  for(int i=1; i<pow(2.0,size); i++){
    for(int j=0;j<size;j++){
      subset[j] = 0;
    }
    
    char *bin;
    bin = getBinary(i);
    int count = 0;
    
    for(int j=0;j<size;j++){
      if(bin[j] == '1'){
        subset[count] = set[j];
        count++;
      }
    }
    
    int sum = 0;
    for(int j=0;j<count;j++){
      sum += subset[j];
    }
    
    if(sum == requiredSum){
      cout << "{";
      for(int j=0;j<count-1;j++){
        cout << subset[j] << ", ";
      }
      cout << subset[count-1] << "}" << endl;
    }
        
  }
}