// Shortest Path Algorithm (Dijkstra's Algorithm)

#include <bits/stdc++.h>
using namespace std;

struct tableItem {
  bool known;
  int dist;
  int path;
};

struct Edge {
  int u, v, w;
};

int main(){
  int nv, ne;
  cin >> nv >> ne;
  tableItem *table = new tableItem[nv];
  for(int i=0; i<nv; i++){
    table[i].known = false;
    table[i].dist = INT_MAX;
    table[i].path = -1;
  }
  Edge *edges = new Edge[ne];
  for(int i=0; i<ne; i++)
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  int start; // start vertex
  cin >> start;
  table[start].dist = 0; // distance of start vertex is 0
  while(true){
    int v = -1; // next vertex
    for(int i=0; i<nv; i++){
      if(!table[i].known && (v == -1 || table[i].dist < table[v].dist)) // find next vertex
        v = i; // choose vertex with minimum distance
    }
    if(v == -1) // if no next vertex found
      break;
    table[v].known = true; // mark vertex as known
    for(int i=0; i<ne; i++){
      if(edges[i].u == v){ // for each edge from v
        int w = edges[i].w; // get weight
        int u = edges[i].v; // get vertex
        if(table[u].dist > table[v].dist + w){
          table[u].dist = table[v].dist + w; // update distance
          table[u].path = v; // update path
        }
      }
    }
  }
  for(int i=0; i<nv; i++)
    cout << "Vertex " << i << ": Distance " << table[i].dist << ", Path " << table[i].path << endl;
  return 0;
}