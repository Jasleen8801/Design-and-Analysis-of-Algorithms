// Matrix Chain Multiplication

#include <bits/stdc++.h>
using namespace std;

void print(int **S, int i, int j){
  if(i == j)
    cout << "A" << i;
  else{
    cout << "(";
    print(S, i, S[i][j]);
    cout << " * ";
    print(S, S[i][j]+1, j);
    cout << ")";
  }
}

int main(){
  int n;
  cin >> n;
  int d[n+1];
  for(int i=0; i<=n; i++)
    cin >> d[i];
  int **M = new int*[n+1];
  int **S = new int*[n+1];
  for(int i=0; i<=n; i++){
    M[i] = new int[n+1];
    S[i] = new int[n+1];
  }
  for(int i=0; i<=n; i++)
    M[i][i] = 0;
  for(int l=2; l<=n; l++){ // l is the chain length
    for(int i=1; i<=n-l+1; i++){ // i is the start index
      int j = i+l-1; // j is the end index
      M[i][j] = INT_MAX;
      for(int k=i; k<=j-1; k++){
        int q = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
        if(q < M[i][j]){
          M[i][j] = q;
          S[i][j] = k;
        }
      }
    }
  }
  cout << "Minimum number of multiplications: " << M[1][n] << endl;
  cout << "Optimal parenthesization: ";
  print(S, 1, n);
  cout << endl;
  return 0;
}

/*
Input:
4
5 4 6 2 7
*/