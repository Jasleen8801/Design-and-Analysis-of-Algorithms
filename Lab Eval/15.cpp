// m Coloring Problem - Backtracking

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, int **adj, int *colors, int nv, int c){
  for(int i=0; i<nv; i++)
    if(adj[v][i] && colors[i] == c)
      return false;
  return true;
}

bool backtrack(int **adj, int *colors, int v, int nv, int m){
  if(v == nv)
    return true;
  for(int c=1; c<=m; c++){ // try all colors
    if(isSafe(v, adj, colors, nv, c)){ // if color is safe
      colors[v] = c; // assign color
      if(backtrack(adj, colors, v+1, nv, m)) // recurse
        return true; // if solution found
      colors[v] = -1; // else backtrack
    }
  }
  return false;
}

int main(){
  int nv, ne, m;
  cin >> nv >> ne >> m;
  int **adj = new int*[nv];
  for(int i=0; i<nv; i++)
    adj[i] = new int[nv];
  for(int i=0; i<nv; i++)
    for(int j=0; j<nv; j++)
      cin >> adj[i][j];
  int *colors = new int[nv];
  for(int i=0; i<nv; i++)
    colors[i] = -1;
  backtrack(adj, colors, 0, nv, m);
  for(int i=0; i<nv; i++)
    cout << "Vertex " << i << ": Color " << colors[i] << endl;
  return 0;
}