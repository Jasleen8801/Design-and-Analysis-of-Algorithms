#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int i, int j){
	if(i == s1.length() || j == s2.length()) 
		return 0;
	if(s1[i] == s2[j]) 
		return 1 + LCS(s1, s2, i+1, j+1);
	return max(LCS(s1, s2, i+1, j), LCS(s1, s2, i, j+1));
}

int LCDdp(string s1, string s2, int i, int j){
	int m = s1.size(), n = s2.size();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[m][n];
}

int main(){
	string s1, s2;
	cout << "Enter the first string: ";
	cin >> s1;
	cout << "Enter the second string: ";
	cin >> s2;
	cout << "Length of LCS using recursion: " << LCS(s1, s2, 0, 0) << endl;
	cout << "Length of LCS using DP: " << LCDdp(s1, s2, 0, 0) << endl;
	return 0;
}