// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

string solve(string s1, string s2, int n, int m){
  int dp[n+1][m+1];
  for(int i=0; i<=n; i++)
    dp[i][0] = 0;
  for(int j=0; j<=m; j++)
    dp[0][j] = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(s1[i-1] == s2[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  string ans = "";
  int i = n, j = m;
  while(i > 0 && j > 0){
    if(s1[i-1] == s2[j-1]){
      ans += s1[i-1];
      i--;
      j--;
    } else {
      if(dp[i][j-1] > dp[i-1][j])
        j--;
      else
        i--;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  string s1, s2;
  cout << "Enter the first string: ";
  cin >> s1;
  cout << "Enter the second string: ";
  cin >> s2;
  int n = s1.length();
  int m = s2.length();  
  string ans = solve(s1, s2, n, m);
  cout << "Longest Common Subsequence: " << ans << endl;
  return 0;
}