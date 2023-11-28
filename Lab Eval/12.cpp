// Hamiltonian Path Problem - Brute Force

#include <bits/stdc++.h>
using namespace std;

bool check_all_permutations(int **adj, int n){
  int* p = new int[n];
  for(int i=0; i<n; i++)
    p[i] = i;
  do {
    bool flag = true;
    for(int i=0; i<n-1; i++){
      if(!adj[p[i]][p[i+1]]){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << "Path: ";
      for(int i=0; i<n; i++)
        cout << p[i] << " ";
      cout << endl;
      return true;
    }
  } while(next_permutation(p, p+n));
  return false;
}

int main(){
  int n;
  cin >> n;
  int **adj = new int*[n];
  for(int i=0; i<n; i++)
    adj[i] = new int[n];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> adj[i][j];
  cout << (check_all_permutations(adj, n) ? "Yes" : "No") << endl;
  return 0;
}