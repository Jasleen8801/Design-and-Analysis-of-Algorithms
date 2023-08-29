// Coin Change Problem

#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int amount){
	int res = 0;
	for(int i=n-1; i>=0; i--){
		int c = amount/coins[i];
		res += c;
		amount -= c*coins[i];
	}
	return res;
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