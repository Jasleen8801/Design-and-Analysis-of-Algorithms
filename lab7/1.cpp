// Backtracking - N Queens Problem

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int ans[], int row, int col){
  for(int i=0; i<row; i++){
    if(ans[i]==col || abs(i-row)==abs(ans[i]-col))
      return false;
  }
  return true;
}

bool backtrack(int ans[], int col, int size){
  if(col==size)
    return true;
  for(int i=0; i<size; i++){
    if(isSafe(ans, col, i)){
      ans[col] = i;
      if(backtrack(ans, col+1, size))
        return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;
  int ans[n];
  memset(ans, -1, sizeof(ans));
  backtrack(ans, 0, n);
  for(int i=0; i<n; i++)
    cout << ans[i]+1 << " ";
  cout << endl;
  return 0;
}