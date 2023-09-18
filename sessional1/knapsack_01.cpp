#include <bits/stdc++.h>
using namespace std;

struct Item{
	int profit;
	int weight;
};

void algo_dp(vector<Item>& items, int capacity){
	int n = items.size();
	vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=capacity; j++){
			if(j < items[i-1].weight)
				dp[i][j] = dp[i-1][j];
			else 
				dp[i][j] = max(dp[i-1][j], items[i-1].profit+dp[i-1][j-items[i-1].weight]);
		}
	}
	cout << "Maximum profit: " << dp[n][capacity] << endl;
}

int main(){
	int n, capacity;
	cout << "Enter number of items: ";
	cin >> n;
	cout << "Enter capacity: ";
	cin >> capacity;
	vector<Item> items(n);
	cout << "Enter profit and weight of each item: " << endl;
	for(int i = 0; i < n; i++){
		cin >> items[i].profit >> items[i].weight;
	}
	algo_dp(items, capacity);
	return 0;
}