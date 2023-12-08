// Fleury Algorithm

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int countEdges(int u, int **graph, int *vis, int nv){
  int count = 0;
  for(int i=0; i<nv; i++){
    if(graph[u][i] && !vis[i])
      count++;
  }
  return count;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;
  int **graph = new int*[MAX];
  for(int i=0; i<MAX; i++)
    graph[i] = new int[MAX];
  memset(graph, 0, sizeof(graph));
  int *vis = new int[nv];
  memset(vis, 0, sizeof(vis));
  for(int i=0; i<ne; i++){
    int u, v;
    cin >> u >> v;
    graph[u][v] = graph[v][u] = 1;
  }
  int start;
  cin >> start;
  int u = start; // start vertex
  cout << u << " ";
  vis[u] = 1; // mark start vertex as visited
  while(countEdges(u, graph, vis, nv)){
    int v = -1; // next vertex
    for(int i=0; i<nv; i++){  // find next vertex
      if(graph[u][i] && !vis[i]){
        if(countEdges(i, graph, vis, nv) == 1){
          v = i;
          break;
        }
      }
    }
    if(v == -1){ // if no next vertex found
      for(int i=0; i<nv; i++){ 
        if(graph[u][i] && !vis[i]){
          v = i; // choose any vertex
          break;
        }
      }
    }
    cout << v << " ";
    vis[v] = 1;
    u = v;
  }
  cout << endl;
  return 0;
}