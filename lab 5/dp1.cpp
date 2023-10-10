// Coin change

#include <bits/stdc++.h>
using namespace std;

int solve(int coins[], int n, int amount){
  int dp[n+1][amount+1];
  for(int i=0; i<n; i++)
    dp[i][0] = 0;
  for(int j=0; j<=amount; j++)
    dp[n-1][j] = j;
  for(int i=n-2; i>=0; i--){
    for(int j=1; j<=amount; j++){
      if(coins[i] > j)
        dp[i][j] = dp[i+1][j];
      else
        dp[i][j] = min(dp[i+1][j], 1+dp[i][j-coins[i]]);
    }
  }
  return dp[0][amount];
}

int main(){
  int n;
  cout << "Enter the no of coins: ";
  cin >> n;
  int coins[n];
  cout << "Enter the coins: ";
  for(int i = 0; i < n; i++){
    cin >> coins[i];
  }
  int amount;
  cout << "Enter the amount: ";
  cin >> amount;
  int ans = solve(coins, n, amount);
  cout << "Minimum no of coins required: " << ans << endl;
  return 0;
}