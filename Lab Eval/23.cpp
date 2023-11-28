// Ford Fulkerson Algorithm - Using Edmonds Karp Algorithm BFS

#include <bits/stdc++.h>
using namespace std;

bool bfs(int **residual, int nv, int s, int t, int *parent){
  bool *visited = new bool[nv];
  for(int i = 0; i < nv; i++){
    visited[i] = false;
  }
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v = 0; v < nv; v++){
      if(visited[v] == false && residual[u][v] > 0){
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return (visited[t] == true);
}

void fordFulkerson(int **adj, int nv, int s, int t){
  int u, v;
  int **residual = new int*[nv]; 
  for(int i = 0; i < nv; i++){
    residual[i] = new int[nv];
    for(int j = 0; j < nv; j++){
      residual[i][j] = adj[i][j];
    }
  }
  int *parent = new int[nv];
  int maxFlow = 0;
  while(bfs(residual, nv, s, t, parent)){
    int pathFlow = INT_MAX;
    for(v = t; v != s; v = parent[v]){
      u = parent[v];
      pathFlow = min(pathFlow, residual[u][v]);
    }
    for(v = t; v != s; v = parent[v]){
      u = parent[v];
      residual[u][v] -= pathFlow;
      residual[v][u] += pathFlow;
    }
    maxFlow += pathFlow;
  }
  cout << maxFlow << endl;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;
  int **adj = new int*[nv];
  for(int i = 0; i < nv; i++){
    adj[i] = new int[nv];
    for(int j = 0; j < nv; j++){
      adj[i][j] = 0;
    }
  }
  for(int i = 0; i < ne; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u][v] = w;
  }
  int s, t;
  cin >> s >> t;
  fordFulkerson(adj, nv, s, t);
}