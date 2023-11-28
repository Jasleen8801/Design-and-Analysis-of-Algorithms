// Topological Sort using DFS

#include <bits/stdc++.h>
using namespace std;

void dfs(int **adj, bool *vis, stack<int> &finishStack, int u, int nv){
  vis[u] = true;
  for(int v=0; v<nv; v++){
    if(adj[u][v] && !vis[v])
      dfs(adj, vis, finishStack, v, nv);
  }
  finishStack.push(u);
}

void topologicalSort(int **adj, int nv, int ne){
  bool *vis = new bool[nv];
  memset(vis, false, sizeof(vis));
  stack<int> finishStack;
  for(int i=0; i<nv; i++)
    if(!vis[i])
      dfs(adj, vis, finishStack, i, nv);
  while(!finishStack.empty()){
    cout << finishStack.top() << " ";
    finishStack.pop();
  }
  cout << endl;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;  
  int **adj = new int*[nv];
  for(int i=0; i<nv; i++)
    adj[i] = new int[nv];
  for(int i=0; i<nv; i++)
    for(int j=0; j<nv; j++)
      cin >> adj[i][j];
  topologicalSort(adj, nv, ne);
}