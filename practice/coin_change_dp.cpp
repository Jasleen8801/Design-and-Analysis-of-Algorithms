// Coin Change Problem
// A amount of money, d[i] array with denomination, c[i][j]-min no of coins to make change for i using first j denominations

#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amount){
	int c[amount+1][n+1];
	for(int i=0; i<=amount; i++)
		c[i][0] = INT_MAX;
	for(int i=0; i<=n; i++)
		c[0][i] = 0;
	for(int i=1; i<=amount; i++){
		for(int j=1; j<=n; j++){
			if(i-coins[j-1] >= 0)
				c[i][j] = min(c[i][j-1], 1+c[i-coins[j-1]][j]);
			else
				c[i][j] = c[i][j-1];
		}
	}
	return c[amount][n];
}

int main() {
	int n;
	cout << "Enter number of coins: ";
	cin >> n;
	int coins[n];
	cout << "Enter coins: ";
	for(int i=0; i<n; i++)
		cin >> coins[i];
	int amount;
	cout << "Enter amount: ";
	cin >> amount;
	cout << "Minimum number of coins required: " << coinChange(coins, n, amount) << endl;
	return 0;
}