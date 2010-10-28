#include <iostream>
using namespace std;

int binomial(int n, int k){
  int b[n+1];
  b[0] = 1;
  
  for(int i=1; i<=n; i++){
    b[i] = 1;
    for(int j=i-1; j>0; j--){
      b[j] += b[j-1];
    }
  }
  return b[k];
}

int main(){
  int n,k; 
  
  cout << "n? ";
  cin >> n;
  cout << "k? ";
  cin >> k;
  cout << "----------" << endl << binomial(n,k) << endl <<  "----------" << endl;
}