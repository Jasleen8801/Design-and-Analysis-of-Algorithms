#include<bits/stdc++.h>
using namespace std;

void algo1(vector<int>& coins, int amount){
	// using coins of greater denomination first
	sort(coins.begin(), coins.end(), greater<int>());
	int i=0, count=0;
	while(amount > 0){
		if(amount >= coins[i]){
			amount -= coins[i];
			count++;
		} else i++;
	}
	cout << "Using coins of greater denomination first: " << count << endl;
}

void algo2(vector<int>& coins, int amount){
	int n = coins.size();
	sort(coins.begin(), coins.end(), greater<int>());
	vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
	for(int i=0; i<=n; i++) 
		dp[i][0] = 0;
	for(int j=0; j<=amount; j++)
		dp[n-1][j] = j;
	for(int i=n-2; i>=0; i--){
		for(int j=1; j<=amount; j++){
			if(coins[i] > j) dp[i][j] = dp[i+1][j];
			else dp[i][j] = min(dp[i+1][j], 1+dp[i][j-coins[i]]);
		}
	}
	cout << "Using DP: " << dp[0][amount] << endl;
}

int main(){
	int n, amount;
	cout << "Enter the number of coins: ";
	cin >> n;
	cout << "Enter the amount: ";
	cin >> amount;
	vector<int> coins(n);
	cout << "Enter the coins: ";
	for(int i=0; i<n; i++) cin >> coins[i];
	algo1(coins, amount);
	algo2(coins, amount);
	return 0;
}