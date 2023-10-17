// Prim's Implementation

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int id;
  bool known;
  int dist;
  int path;
};

vector<int> dijkstra(vector<vector<int> > w, vector<Node> nodes, int s){
  nodes[s].dist = 0; 
  while(true){
    int minDist = INT_MAX;
    int minNode = -1;
    for(int i=0; i<nodes.size(); i++) 
      if(!nodes[i].known && nodes[i].dist < minDist){
        minDist = nodes[i].dist;
        minNode = i;
      }
    if(minNode == -1) break;
    nodes[minNode].known = true;
    for(int i=0; i<nodes.size(); i++){
      if(!nodes[i].known && w[minNode][i] != INT_MAX){
        if(nodes[minNode].dist + w[minNode][i] < nodes[i].dist){
          nodes[i].dist = nodes[minNode].dist + w[minNode][i];
          nodes[i].path = minNode;
        }
      }
    }
  }
  vector<int> ans;
  for(int i=0; i<nodes.size(); i++){
    ans.push_back(nodes[i].dist);
  }
  return ans;
}

int main(){
  int n, m;
  cout << "Enter number of vertices: ";
  cin >> n;
  cout << "Enter number of edges: ";
  cin >> m;
  vector<vector<int> > w(n, vector<int>(n, INT_MAX)); // weight matrix
  vector<Node> nodes(n);
  for(int i=0; i<n; i++){
    nodes[i].id = i;
    nodes[i].known = false;
    nodes[i].dist = INT_MAX;
    nodes[i].path = -1;
  }
  for(int i=0; i<m; i++){
    int u, v, wt;
    cout << "Enter edge " << i+1 << ": ";
    cin >> u >> v >> wt;
    w[u][v] = wt;
    w[v][u] = wt;
  }
  int s;
  cout << "Enter source: ";
  cin >> s;
  nodes[s].dist = 0; 
  vector<int> ans = dijkstra(w, nodes, s);
  for(int i=0; i<n; i++){
    cout << "Distance from " << s << " to " << i << ": " << ans[i] << endl;
  }
  return 0;
}