// Graph Coloring Problem

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int** adj, int c, int k, int color[], int n){
  for(int i=0; i<=n; i++){
    if(adj[k][i] && c==color[i])
      return false;
  }
  return true;
}

bool backtrack(int** adj, int color[], int k, int n, int m){
  for(int c=1; c<=m; c++){
    if(isSafe(adj, c, k, color, n)){
      color[k] = c;
      if(k==n)
        return true;
      else if(backtrack(adj, color, k+1, n, m))
        return true;
      color[k] = -1;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  int **adj = new int*[n];
  for(int i=0; i<n; i++){
    adj[i] = new int[n];
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  }
  int m;
  cin >> m;
  int color[m];
  memset(color, -1, sizeof(color));
  bool flag = backtrack(adj, color, 0, n, m);
  if(flag) cout << "The m color solution exists\n";
  else cout << "The m color solution does not exist\n";
  return 0;
}