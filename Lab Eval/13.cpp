// Hamiltonian Path Problem - Backtracking

#include <bits/stdc++.h>
using namespace std;

void printSolution(int *path, int V){
  cout << "Solution exists" << endl;
  for(int i=0; i<V; i++)
    cout << path[i] << " ";
  cout << path[0] << endl;
}

bool isSafe(int v, bool **graph, int *path, int pos){
  if(!graph[path[pos-1]][v])
    return false;
  for(int i=0; i<pos; i++)
    if(path[i] == v)
      return false;
  return true;
}

bool hamCycleUtil(bool **graph, int *path, int pos, int V){
  if(pos == V){
    if(graph[path[pos-1]][path[0]])
      return true;
    else
      return false;
  }
  for(int v=1; v<V; v++){
    if(isSafe(v, graph, path, pos)){
      path[pos] = v;
      if(hamCycleUtil(graph, path, pos+1, V))
        return true;
      path[pos] = -1;
    }
  }
  return false;
}

bool hamCycle(bool **graph, int V){
  int *path = new int[V];
  for(int i=0; i<V; i++)
    path[i] = -1;
  path[0] = 0;
  if(!hamCycleUtil(graph, path, 1, V)){
    cout << "No solution" << endl;
    return false;
  }
  printSolution(path, V);
  return true;
}

int main(){
  int V;
  cin >> V;
  bool **graph = new bool*[V];
  for(int i=0; i<V; i++)
    graph[i] = new bool[V];
  for(int i=0; i<V; i++)
    for(int j=0; j<V; j++)
      cin >> graph[i][j];
  hamCycle(graph, V);
  return 0;
}