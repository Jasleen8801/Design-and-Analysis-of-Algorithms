// Prim's Implementation

#include <bits/stdc++.h>
using namespace std;

struct tableItem {
  bool known;
  int dist;
  int path;
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
  int **graph = new int*[nv];
  for(int i=0; i<nv; i++)
    graph[i] = new int[nv];
  for(int i=0; i<nv; i++)
    for(int j=0; j<nv; j++)
      cin >> graph[i][j];
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
    for(int i=0; i<nv; i++){
      if(graph[v][i]){
        int w = graph[v][i];
        int u = i;
        if(table[u].dist > w){
          table[u].dist = w;
          table[u].path = v;
        }
      }
    }
    int totalWt = 0;
    for(int i=0; i<nv; i++)
      totalWt += table[i].dist;
    cout << "Total Weight: " << totalWt << endl;
    return 0;
  }
}