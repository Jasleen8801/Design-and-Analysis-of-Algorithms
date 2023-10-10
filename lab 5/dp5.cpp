// Travelling salesman problem 

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout << "Enter the no of cities: ";
  cin >> n;
  int cost[n][n];
  cout << "Enter the cost matrix: " << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> cost[i][j];
    }
  }
  // int ans = solve(cost, n);
}