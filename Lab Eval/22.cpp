// Floyd Warshell Algorithm

#include <bits/stdc++.h>
using namespace std;

int main(){
  int nv, ne;
  cin >> nv >> ne;
  int **adj = new int*[nv];
  for(int i = 0; i < nv; i++){
    adj[i] = new int[nv];
    for(int j = 0; j < nv; j++){
      adj[i][j] = INT_MAX;
    }
  }
  for(int i = 0; i < ne; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u][v] = w;
  }
  for(int k = 0; k < nv; k++){
    for(int i = 0; i < nv; i++){
      for(int j = 0; j < nv; j++){
        if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }
  }
  for(int i = 0; i < nv; i++){
    for(int j = 0; j < nv; j++){
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}