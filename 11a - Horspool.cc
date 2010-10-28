#include <iostream>
using namespace std;

#define pattern "abcd"
#define text "sfhsgasdfafhasfadabcdafhgasdg"
#define ASIZE 128

void build_table(char *x, int m, int bmBc[]) {
  int i;
   for (i = 0; i < ASIZE; ++i)
      bmBc[i] = m;
    for (i = 0; i < m - 1; ++i)
       bmBc[x[i]] = m - i - 1;
}

void horspool(char *x, int m, char *y, int n) {
   int j, bmBc[ASIZE];
   char c;

   build_table(x, m, bmBc);

   /*
    Search.
   */
   j = 0;
   while (j <= n - m) {
      c = y[j + m - 1];
      if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0){
         cout << "Found at position " << j << "." << endl;
         return;
      }
      j += bmBc[c];
   }
}

int main(){
  char haystack[256] = text;
  char needle[256] = pattern;
  
  //Find length
  int i=0;
  while(needle[i] != '\0'){
    i++;
  }
  int nlen = i;
  
  i = 0;
  while(haystack[i] != '\0'){
    i++;
  }
  int hlen = i;
  
  horspool(needle, nlen, haystack, hlen);
  return 0;
}