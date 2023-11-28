// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

int main(){
  string A, B;
  cin >> A >> B;
  int m = A.length();
  int n = B.length();
  int **dp = new int*[m+1];
  for(int i=0; i<=m; i++)
    dp[i] = new int[n+1];
  for(int i=0; i<=m; i++)
    dp[i][0] = 0;
  for(int j=0; j<=n; j++)
    dp[0][j] = 0;
  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      if(A[i-1] == B[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }
  cout << "The length of longest common subsequence is: " << dp[m][n] << endl;

  string ans = "";
  int i = m, j = n;
  while(i > 0 && j > 0){
    if(A[i-1] == B[j-1]){
      ans += A[i-1];
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
  cout << "The longest common subsequence is: " << ans << endl;
  return 0;
}