// Rabin Karp Algorithm

#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int p){
  int res = 1;
  x = x % p;
  while(y > 0){
    if(y & 1)
      res = (res*x) % p;
    y = y>>1;
    x = (x*x) % p;
  }
  return res;
}

void RabinKarp(char *T, char *P, int q, int d, int n, int m){
  int h = power(d, m-1, q); // h = d^(m-1) % q
  int p = 0; 
  int *t = new int[n-m+1];
  for(int i=0; i<m; i++){ // Preprocessing
    p = (d*p + P[i]) % q;
    t[0] = (d*t[0] + T[i]) % q;
  }
  for(int s=0; s<=n-m; s++){
    if(p == t[s]){
      int i = 0;
      while(i<m && P[i] == T[s+i])
        i++;
      if(i == m)
        cout << "Pattern found at index " << s << endl;
    }
    if(s < n-m)
      t[s+1] = (d*(t[s] - T[s]*h) + T[s+m]) % q;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  char *T = new char[n];
  char *P = new char[m];
  cin >> T >> P;
  int q, d;
  cin >> q >> d;
  RabinKarp(T, P, q, d, n, m);
  return 0;
}