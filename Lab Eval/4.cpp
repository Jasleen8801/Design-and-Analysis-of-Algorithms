// Coin Change Problem

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int coins[n];
  for(int i=0; i<n; i++)
    cin >> coins[i];
  int amount;
  cin >> amount;
  int **dp = new int*[n+1];
  for(int i=0; i<=n; i++)
    dp[i] = new int[amount+1];
  for(int i=0; i<=n; i++)
    dp[i][0] = 0;
  for(int j=0; j<=amount; j++)
    dp[n][j] = j;
  for(int i=n-1; i>=0; i--){
    for(int j=1; j<=amount; j++){
      if(coins[i] > j)
        dp[i][j] = dp[i+1][j];
      else
        dp[i][j] = min(dp[i+1][j], 1 + dp[i][j-coins[i]]);
    }
  }
  cout << dp[0][amount] << endl;
  return 0;
}

/*
Input:

3
1 6 10
12
*/