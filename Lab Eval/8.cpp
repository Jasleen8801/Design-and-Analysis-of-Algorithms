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
  int s = 0;
  int V[n-1]; // V is the set of vertices other than s
  int idx = 0;
  for(int i=0; i<n; i++)
    if(i != s)
      V[idx++] = i;
  int min_path = INT_MAX;
  do{
    int curr = 0; // curr is the current cost
    int k = s; // k is the last vertex visited
    for(int i=0; i<n-1; i++){
      curr += cost[k][V[i]]; // cost of going from k to V[i]
      k = V[i]; // update k
    }
    curr += cost[k][s]; // cost of going from k to s
    min_path = min(min_path, curr); // update min_path
  } while(next_permutation(V, V+n-1));
  cout << "Minimum cost: " << min_path << endl;
}

/*
Input:
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
*/