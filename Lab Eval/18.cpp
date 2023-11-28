// Minimum Spanning Tree 

#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int u, v, w;
};

bool isConnected(Edge *edges, int ne, int nv){
  bool *vis = new bool[nv];
  memset(vis, false, sizeof(vis));
  vis[0] = true;
  int count = 1;
  while(count < nv){
    bool flag = false;
    for(int i=0; i<ne; i++){
      if(vis[edges[i].u] && !vis[edges[i].v]){
        vis[edges[i].v] = true;
        count++;
        flag = true;
      }
      else if(vis[edges[i].v] && !vis[edges[i].u]){
        vis[edges[i].u] = true;
        count++;
        flag = true;
      }
    }
    if(!flag)
      return false;
  }
  return true;
}

void disconnectGraph(Edge* edges, int ne, int nv){
  sort(edges, edges+ne, [](Edge a, Edge b){
    return a.w < b.w;
  });
  for(int i=0; i<ne; i++){
    if(!isConnected(edges, ne, nv)){
      cout << edges[i].u << " " << edges[i].v << endl;
      return;
    }
  }
  cout << "No disconnecting edge found" << endl;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;
  Edge *edges = new Edge[ne];
  for(int i=0; i<ne; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  disconnectGraph(edges, ne, nv);
  return 0;
}