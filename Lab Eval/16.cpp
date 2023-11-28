// Kahn's ALgorithm

#include <bits/stdc++.h>
using namespace std;

int *topologicalSort(int **adj, int nv, int ne){
  int *indegree = new int[nv];
  memset(indegree, 0, sizeof(indegree));
  for(int i=0; i<nv; i++)
    for(int j=0; j<nv; j++)
      if(adj[i][j])
        indegree[j]++;
  stack<int> s;
  for(int i=0; i<nv; i++)
    if(indegree[i] == 0)
      s.push(i);
  int *sorted = new int[nv];
  int i = 0;
  while(!s.empty()){
    int u = s.top();
    s.pop();
    sorted[i++] = u;
    for(int v=0; v<nv; v++){
      if(adj[u][v]){
        indegree[v]--;
        if(indegree[v] == 0)
          s.push(v);
      }
    }
  }
  return sorted;
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
  int *sorted = topologicalSort(adj, nv, ne);
  for(int i=0; i<nv; i++)
    cout << sorted[i] << " ";
  cout << endl;
  return 0;
}