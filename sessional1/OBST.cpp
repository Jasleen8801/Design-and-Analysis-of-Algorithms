// Optimal Binary Search Tree - DP

#include <bits/stdc++.h>
using namespace std;

struct Value{
	int weight;
	int cost;
	int root;
};

void obst_dp(vector<int>& p, vector<int>& q, int n){
	vector<vector<Value>>dp(n+2, vector<Value>(n+1));
	// w[i,j] = p(j) + q(j) + w(i,j-1)
	// c[i,j] = min(c[i,k-1] + c[k+1,j] + w[i,j]) for i<k<=j
	// r[i,j] = k for which c[i,j] is minimum
	for(int i=0; i<n; i++){
		dp[i][i].weight = q[i];
		dp[i][i].cost = 0;
		dp[i][i].root = 0;
	}
	for(int len=2; len<=n; len++){
		for(int i=0; i<=n-len+1; i++){
			int j = i + len - 1;
			dp[i][j].weight = dp[i][j-1].weight + p[j] + q[j];
			dp[i][j].cost = INT_MAX;
			dp[i][j].root = -1;
			for(int k=i+1; k<=j; k++){
				int cost = dp[i][k-1].cost + dp[k][j].cost + dp[i][j].weight;
				if(cost < dp[i][j].cost){
					dp[i][j].cost = cost;
					dp[i][j].root = k;
				}
			}
		}
	}
	cout << "Cost of optimal BST: " << dp[0][n-1].cost << endl;
	cout << "Root of optimal BST: " << dp[0][n-1].root << endl;
}

int main(){
  int n;
	cout << "Enter the number of nodes: ";
	cin >> n;
	vector<int>p(n+1), q(n+1);
	cout << "Enter the probability of successful search: ";
	for(int i=1; i<=n; i++)
		cin >> p[i];
	cout << "Enter the probability of unsuccessful search: ";
	for(int i=0; i<=n; i++)
		cin >> q[i];
	obst_dp(p, q, n);
	return 0;
}