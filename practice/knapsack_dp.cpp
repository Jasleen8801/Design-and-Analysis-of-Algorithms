// 0-1 Knapsack - DP Approach

#include <bits/stdc++.h>
using namespace std;

struct Item{
  int weight;
	int profit;
	string name;
};

int knapsack(int c, Item items[], int n) {
	int dp[n+1][c+1];
	for(int i=0; i<=n; i++) 
		dp[i][0] = 0;
	for(int i=0; i<=c; i++) 
		dp[0][i] = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=c; j++){
			if(j<items[i-1].weight) 
				dp[i][j] = dp[i-1][j];
			else 
				dp[i][j] = max(dp[i-1][j], items[i-1].profit + dp[i-1][j-items[i-1].weight]);
		}
	}

	bool selected[n+1];
	for(int i=0; i<=n; i++) 
		selected[i] = false;
	int i=n, j=c;
	while(i>0 && j>0) {
		if(dp[i][j] == dp[i-1][j]) 
			i--;
		else {
			selected[i-1] = true;
			j -= items[i-1].weight;
		}
	}

	for(int i=0; i<n; i++) 
		if(selected[i]) cout << items[i].name << " ";
	cout << endl;

	return dp[n][c];
}



int main() {
	int capacity;
	cin >> capacity;
	int n;
	cin >> n;
	Item items[n];
	for(int i=0; i<n; i++) {
		cin >> items[i].weight >> items[i].profit;
		items[i].name = "J" + to_string(i+1);
	}
	cout << knapsack(capacity, items, n) << endl;
	return 0;
}