// Travelling Salesman Problem using Branch and Bound

#include <bits/stdc++.h>
using namespace std;

int findReducedMatrix(int** adj, int n, bool isRow){
  int m[n]; //minimum in each row/column
  for(int i=0; i<n; i++){
    int min = INT_MAX;
    for(int j=0; j<n; j++){
      if(isRow){
        if(adj[i][j]<min)
          min = adj[i][j];
      }
      else{
        if(adj[j][i]<min)
          min = adj[j][i];
      }
    }
    m[i] = min; 
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(isRow){
        if(adj[i][j]!=INT_MAX && m[i]!=INT_MAX)
          adj[i][j] -= m[i];
      }
      else{
        if(adj[j][i]!=INT_MAX && m[i]!=INT_MAX)
          adj[j][i] -= m[i];
      }
    }
  }
  int ans = 0;
  for(int i=0; i<n; i++)
    ans += m[i];
  return ans;
}

int main(){
  int n;
  cin >> n;
  int **adj = new int*[n];
  for(int i=0; i<n; i++){
    adj[i] = new int[n];
    for(int j=0; j<n; j++){
      cin >> adj[i][j];
      if(adj[i][j]==-1)
        adj[i][j] = INT_MAX;
    }
  }
  int start;
  cin >> start;
  int ans[n];
  memset(ans, -1, sizeof(ans));
  ans[0] = start;
  int x = findReducedMatrix(adj, n, true);
  int y = findReducedMatrix(adj, n, false);
  cout << "Reduced Matrix for start-0: " << endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cout << adj[i][j] << " ";
    cout << endl;
  }
  cout << "Initial Cost: " << x+y << endl;
  bool vis[n];
  memset(vis, false, sizeof(vis));
  vis[start] = true;
  
}

/*
5
-1 10 17 0 1
12 -1 11 2 0
0 3 -1 0 2
15 3 12 -1 0
11 0 0 12 -1
0
*/