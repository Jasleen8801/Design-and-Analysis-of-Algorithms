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
  int start;
  cin >> start;
  table[start].dist = 0;
  while(true){
    int v = -1;
    for(int i=0; i<nv; i++){
      if(!table[i].known && (v == -1 || table[i].dist < table[v].dist))
        v = i;
    }
    if(v == -1)
      break;
    table[v].known = true;
    for(int i=0; i<ne; i++){
      if(edges[i].u == v){
        int w = edges[i].w;
        int u = edges[i].v;
        if(table[u].dist > table[v].dist + w){
          table[u].dist = table[v].dist + w;
          table[u].path = v;
        }
      }
    }
  }
  for(int i=0; i<nv; i++)
    cout << "Vertex " << i << ": Distance " << table[i].dist << ", Path " << table[i].path << endl;
  return 0;
}