// Minimum Spanning Tree - Kruskal's Algo

#include <bits/stdc++.h>
using namespace std; 

struct Edge {
  int u, v, w;
};

bool isCycle(Edge *edges, int ne, int nv){
  int *parent = new int[nv]; // parent array
  for(int i=0; i<nv; i++)
    parent[i] = i; // initialize parent array
  for(int i=0; i<ne; i++){ // for each edge
    int u = edges[i].u, v = edges[i].v; // get vertices
    int pu = parent[u], pv = parent[v]; // get parents
    if(pu == pv) // if parents are same
      return true;
    for(int j=0; j<nv; j++) // update parent array
      if(parent[j] == pv) // if parent is pv
        parent[j] = pu; // make parent as pu
  }
  return false;
}

void connectGraph(Edge *edges, int ne, int nv, Edge *ans){
  sort(edges, edges+ne, [](Edge a, Edge b){
    return a.w < b.w;
  }); // sort edges by weight
  int count = 0; // count of edges
  for(int i=0; i<ne; i++){ // for each edge
    ans[count++] = edges[i]; // add edge to ans
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