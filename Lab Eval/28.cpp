// Naive String Matching

#include <bits/stdc++.h>
using namespace std;

void NaiveStringMatching(string T, string P, int n, int m){
  for(int s=0; s<=n-m; s++){
    bool match = true;
    for(int i=0; i<m; i++)
      if(T[s+i] != P[i]){
        match = false;
        break;
      }
    if(match)
      cout << "Pattern occurs with shift " << s << endl;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  char *T = new char[n];
  char *P = new char[m];
  cin >> T >> P;
  NaiveStringMatching(T, P, n, m);
  return 0;
}