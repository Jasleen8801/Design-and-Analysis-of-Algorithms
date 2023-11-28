// N Queen Problem

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int *res, int row, int col){
  for(int i=0; i<row; i++){
    if(res[i] == col || abs(res[i]-col) == abs(i-row)){
      return false;
    }
  }
  return true;
}

void placeQueens(int *res, int row, int n){
  for(int i=0; i<n; i++){
    if(isSafe(res, row, i) == 1){
      res[row] = i;
      if(row == n-1){
        for(int j=0; j<n; j++){
          cout << res[j] << " ";
        }
        cout << endl;
      }
      else{
        placeQueens(res, row+1, n);
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  int *res = new int[n];
  placeQueens(res, 0, n);
  return 0;
}