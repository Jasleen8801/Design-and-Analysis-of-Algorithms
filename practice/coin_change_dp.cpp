// Coin Change DP
// Minimization Problem
// Bottom Up Approach

#include <bits/stdc++.h>
using namespace std;

int minCoinsDP(int coin[], int amount, int n) {
	int dp[n + 1][amount + 1];
	for(int i=0; i<=n; i++) dp[i][0] = 0;
	for(int j=1; j<=amount; j++) dp[0][j] = INT_MAX - 1;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=amount; j++){
			if(coin[i-1] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coin[i-1]]);
		}
	}

  return dp[n][amount];
}

int main() {
	int n, amount;
	cout << "Enter the number of coins: ";
	cin >> n;
	cout << "Enter the amount: ";
	cin >> amount;
	int coin[n];
	cout << "Enter the coins: ";
	for(int i=0; i<n; i++) cin >> coin[i];
  cout << minCoinsDP(coin, amount, n) << endl;

  return 0;
}
