// 0/1 Knapsack

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int profit;
  string id;
};

int main(){
  int n;
  cin >> n;
  Item arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i].profit >> arr[i].weight;
    arr[i].id = to_string(i+1);
  }
  int capacity;
  cin >> capacity;
  int **dp = new int*[n+1];
  for(int i=0; i<=n; i++)
    dp[i] = new int[capacity+1];
  for(int i=0; i<=n; i++)
    dp[i][0] = 0;
  for(int j=0; j<=capacity; j++)
    dp[0][j] = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=capacity; j++){
      if(arr[i-1].weight > j)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = max(dp[i-1][j], arr[i-1].profit + dp[i-1][j-arr[i-1].weight]);
    }
  }
  cout << dp[n][capacity] << endl;
  return 0;
}

/*
Input:
4
15 1
10 5
9 3
5 4
8
*/