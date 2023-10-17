// Dijkstra Theorem

#include <bits/stdc++.h>
using namespace std;

struct Node{
  int id;
  bool known;
  int dist;
  int path;
};

vector<int> dijkstra(vector<vector<int> > w, vector<Node> nodes, int s){
  nodes[s].dist = 0; // distance from source to source is 0
  while(true){
    int minDist = INT_MAX; // minimum distance
    int minNode = -1; // minimum node
    for(int i=0; i<nodes.size(); i++) 
      if(!nodes[i].known && nodes[i].dist < minDist){ // if node is not known and distance is less than minimum distance
        minDist = nodes[i].dist; // update minimum distance
        minNode = i; // update minimum node
      }
    if(minNode == -1) break; // if no minimum node found, break
    nodes[minNode].known = true;  
    for(int i=0; i<nodes.size(); i++){
      if(!nodes[i].known && w[minNode][i] != INT_MAX){
        // if node is not known and there is an edge between minNode and i
        if(nodes[minNode].dist + w[minNode][i] < nodes[i].dist){
          // if distance from source to minNode + weight of edge between minNode and i is less than distance from source to i
          nodes[i].dist = nodes[minNode].dist + w[minNode][i]; // update distance from source to i
          nodes[i].path = minNode; // update path of i
        }
      }
    }
  }
  vector<int> ans; 
  for(int i=0; i<nodes.size(); i++){
    ans.push_back(nodes[i].dist); // push distance from source to i
  }
  return ans;
}

int main(){
  int n, m;
  cout << "Enter number of vertices: ";
  cin >> n;
  cout << "Enter number of edges: ";
  cin >> m;
  vector<vector<int> > w(n); // weight matrix
  vector<Node> nodes(n);
  for(int i=0; i<n; i++){
    nodes[i].id = i;
    nodes[i].known = false;
    nodes[i].dist = INT_MAX;
    nodes[i].path = -1;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      w[i].push_back(INT_MAX);
    }
  }
  cout << "Enter edges and their weights:\n";
  for(int i=0; i<m; i++){
    int u, v, weight;
    cin >> u >> v >> weight;
    w[u][v] = weight;
  }
  vector<int> ans = dijkstra(w, nodes, 0);
  for(int i=0; i<n; i++){
    cout << "Distance from 0 to " << i << " is " << ans[i] << endl;
  }
  return 0;
}