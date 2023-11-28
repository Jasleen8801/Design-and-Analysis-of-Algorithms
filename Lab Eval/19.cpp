// Minimum Spanning Tree - Kruskal's Algo

#include <bits/stdc++.h>
using namespace std; 

struct Edge {
  int u, v, w;
};

bool isCycle(Edge *edges, int ne, int nv){
  int *parent = new int[nv];
  for(int i=0; i<nv; i++)
    parent[i] = i;
  for(int i=0; i<ne; i++){
    int u = edges[i].u, v = edges[i].v;
    int pu = parent[u], pv = parent[v];
    if(pu == pv)
      return true;
    for(int j=0; j<nv; j++)
      if(parent[j] == pv)
        parent[j] = pu;
  }
  return false;
}

void connectGraph(Edge *edges, int ne, int nv, Edge *ans){
  sort(edges, edges+ne, [](Edge a, Edge b){
    return a.w < b.w;
  });
  int count = 0;
  for(int i=0; i<ne; i++){
    ans[count++] = edges[i];
    if(!isCycle(ans, count, nv)){
      cout << edges[i].u << " " << edges[i].v << endl;
      return;
    }
  }
  cout << "No connecting edge found" << endl;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;
  Edge *edges = new Edge[ne];
  for(int i=0; i<ne; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  Edge *ans;
  connectGraph(edges, ne, nv, ans);
  return 0;
}