// Boyre Moore Algorithm

#include <bits/stdc++.h>
using namespace std;

int main(){
  string T, P;
  cin >> T >> P;
  int n = T.length();
  int m = P.length();
  int *last = new int[256];
  for(int i=0; i<256; i++)
    last[i] = -1;
  for(int i=0; i<m; i++)
    last[P[i]] = i;
  int s = 0;
  while(s <= n-m){
    int j = m-1;
    while(j >= 0 && P[j] == T[s+j])
      j--;
    if(j < 0){
      cout << "Pattern occurs with shift " << s << endl;
      s += (s+m < n) ? m-last[T[s+m]] : 1;
    } else {
      s += max(1, j-last[T[s+j]]);
    }
  }
  return 0;
}