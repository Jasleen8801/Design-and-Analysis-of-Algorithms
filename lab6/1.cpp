// Fleury's Algorithm

#include <bits/stdc++.h>
using namespace std;

bool isBridge(vector<vector<int> > adj, int u, int v){
  int count = 0;
  for(int i=0; i<adj[u].size(); i++){
    if(adj[u][i] == v)
      count++;
  }
  if(count == 1)
    return true;
  return false;
}

vector<int> fleury(vector<vector<int> >& adj, int n, vector<int>& deg){
  vector<int> path;
  int start = 0;
  for(int i=0; i<n; i++)
    if(deg[i]%2 == 1){
      start = i;
      break;
    }
  path.push_back(start);
  int u = start;
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    if(isBridge(adj, u, v)){
      path.push_back(v);
      deg[u]--;
      deg[v]--;
      adj[u].erase(adj[u].begin()+i);
      adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
      u = v;
      i = -1;
    }
  }
  for(int i=0; i<n; i++){
    if(deg[i] > 0){
      u = i;
      break;
    }
  }
  for(int i=0; i<adj[u].size(); i++){
    int v = adj[u][i];
    path.push_back(v);
    deg[u]--;
    deg[v]--;
    adj[u].erase(adj[u].begin()+i);
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
    u = v;
    i = -1;
  }
  return path;
}

int main(){
  int n, m;
  cout << "Enter number of vertices: ";
  cin >> n;
  cout << "Enter number of edges: ";
  cin >> m;
  vector<vector<int> > adj(n);
  vector<int> deg(n, 0);
  cout << "Enter edges: \n";
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  vector<int> path = fleury(adj, n, deg);
  cout << "Eulerian Path: ";
  for(int i=0; i<path.size(); i++)
    cout << path[i] << " ";

  return 0;
}