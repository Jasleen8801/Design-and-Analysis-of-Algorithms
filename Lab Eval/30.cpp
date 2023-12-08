// KMP Algorithm

#include <bits/stdc++.h>
using namespace std;

void compute_prefix_func(char *P, int m, int *pi){
  pi[0] = 0;
  int k = 0; // k is the length of the longest prefix of P[0..q-1] that is also a suffix of P[0..q-1]
  for(int q=1; q<m; q++){ // q is the index of the pattern
    while(k>0 && P[k]!=P[q]){
      k = pi[k]; // pi[k] is the length of the longest prefix of P[0..k-1] that is also a suffix of P[0..q-1]
    }
    if(P[k]==P[q]){
      k++; // k is the length of the longest prefix of P[0..q-1] that is also a suffix of P[0..q-1]
    }
    pi[q] = k;
  }
}

void kmp_matcher(char *T, char *P, int n, int m){
  int *pi = new int[m];
  compute_prefix_func(P, m, pi);
  int q = 0;
  for(int i=0; i<n; i++){
    while(q>0 && P[q]!=T[i]){
      q = pi[q];
    }
    if(P[q]==T[i]){
      q++;
    }
    if(q==m){
      cout << "Pattern occurs with shift " << i-m+1 << endl;
      q = pi[q-1];
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  char *T = new char[n];
  char *P = new char[m];
  cin >> T >> P;
  kmp_matcher(T, P, n, m);
  return 0;
}