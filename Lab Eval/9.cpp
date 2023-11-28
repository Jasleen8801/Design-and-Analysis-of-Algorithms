// Travelling Salesman Problem

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int **cost = new int*[n];
  for(int i=0; i<n; i++)
    cost[i] = new int[n];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> cost[i][j];
  int s;
  cin >> s; 
  int **g = new int*[n]; // g[i][S] is the cost of going from i to s via the vertices in S
  for(int i=0; i<n; i++)
    g[i] = new int[1<<n]; // 1<<n is 2^n 
  for(int i=0; i<n; i++)
    for(int j=0; j<(1<<n); j++)
      g[i][j] = INT_MAX; 
  for(int i=0; i<n; i++)
    g[i][0] = cost[i][s]; // cost of going from i to s
  for(int S=1; S<(1<<n); S++){ // for each subset of vertices
    for(int i=0; i<n; i++){ // for each vertex
      if(S & (1<<i)){ // if i is in S
        for(int j=0; j<n; j++){ // for each vertex
          if(j != i && (S & (1<<j))){ // if j is in S and j != i
            g[i][S] = min(g[i][S], cost[i][j] + g[j][S^(1<<j)]); // update g[i][S]
          }
        }
      }
    }
  }
  int min_path = INT_MAX;
  for(int i=0; i<n; i++)
    min_path = min(min_path, g[i][(1<<n)-1]); // update min_path
  cout << "Minimum cost: " << min_path << endl;

  return 0;
}

/*
Input:
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
*/