// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

int solve(int weights[], int values[], int n, int cap){
  int dp[n+1][cap+1];
  for(int i=0; i<=n; i++)
    dp[i][0] = 0;
  for(int j=0; j<=cap; j++)
    dp[0][j] = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=cap; j++){
      if(weights[i-1] > j)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
    }
  }
  return dp[n][cap];
}

int main(){
  int cap;
  cout << "Enter the capacity of the knapsack: ";
  cin >> cap;
  int n;
  cout << "Enter the no of items: ";
  cin >> n;
  int weights[n], values[n];
  cout << "Enter the weights: ";
  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }
  cout << "Enter the values: ";
  for(int i = 0; i < n; i++){
    cin >> values[i];
  }
  int profit = solve(weights, values, n, cap);
  cout << "Maximum profit: " << profit << endl;
  return 0;
}