// Travelling Salesman Problem using Dynamic Programming

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;

int n, dist[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int tsp(int u, int mask){
  if(mask == (1 << n) - 1)
		return dist[u][0];
	if(dp[mask][u] != -1)
		return dp[mask][u];

	int ans = INT_MAX;
	for(int v = 0; v < n; v++){
		if(!(mask & (1 << v)))
			ans = min(ans, dist[u][v] + tsp(v, mask | (1 << v)));
	}
	return dp[mask][u] = ans;
}

int main() {
	cout << "Enter number of cities: ";
	cin >> n;
	cout << "Enter distance matrix: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> dist[i][j];
		}
	}
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}
	cout << "Minimum distance: " << tsp(0, 1) << endl;
	return 0;
}