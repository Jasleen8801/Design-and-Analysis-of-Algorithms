// Matrix Multiplication 

#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){
  int M[n+1][n+1];
  int S[n+1][n+1];
  for(int i=0; i<=n; i++)
    M[i][i] = 0;
  for(int i=2; i<=n; i++){
    for(int j=1; j<=n-i+1; j++){
      int k = j+i-1;
      M[j][k] = INT_MAX;
      for(int l=j; l<k; l++){
        int cost = M[j][l] + M[l+1][k] + arr[j-1]*arr[l]*arr[k];
        if(cost < M[j][k]){
          M[j][k] = cost;
          S[j][k] = l;
        }
      }
    }
  }
  cout << "M matrix: " << endl;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << "S matrix: " << endl;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cout << S[i][j] << " ";
    }
    cout << endl;
  }
  return M[1][n];
}

int main(){
  int n;
  cout << "Enter the no of matrices: ";
  cin >> n;
  int arr[n+1];
  cout << "Enter the dimensions: ";
  for(int i = 0; i <= n; i++)
    cin >> arr[i];
  int ans = solve(arr, n);
  cout << endl << "Minimum no of multiplications: " << ans << endl;
  return 0;
}