#include <bits/stdc++.h>
using namespace std;

// TO BE DONE AGAIN!!!

int tsp_dp(vector<vector<int>> &cost, vector<int> &vis, int curr, int cities_left){
	int n = cost.size();
	if(cities_left == 0){
		return cost[curr][0];
	}
	if(vis[curr] == 1){
		return INT_MAX;
	}
	vis[curr] = 1;
	int min_cost = INT_MAX;
	for(int city=0; city<n; city++){
		if(city!=curr && !vis[city]){
			int cost_to_city = cost[curr][city] + tsp_dp(cost, vis, city, cities_left-1); 
			min_cost = min(min_cost, cost_to_city);
		}
	}
	vis[curr] = 0;
	return min_cost;
}

int main(){
	int n;
	cout << "Enter the number of cities: ";
	cin >> n;

	vector<vector<int>> cost(n, vector<int>(n));
	cout << "Enter the cost matrix: " << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> cost[i][j];
		}
	}
	vector<int> vis(n,0);
	int start = 0;
	int min_cost = tsp_dp(cost, vis, start, n-1);
	cout << "Minimum cost: " << min_cost << endl;
	return 0;
}
