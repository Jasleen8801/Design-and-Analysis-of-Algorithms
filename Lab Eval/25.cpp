// Sum of Subsets

#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int p, int r){
  int i = p-1;
  while(p<r){
    if(arr[p]<arr[r]){
      i++;
      swap(arr[i], arr[p]);
    }
    p++;
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void sort(int *arr, int p, int r){
  if(p<r){
    int q = partition(arr, p, r);
    sort(arr, p, q-1);
    sort(arr, q+1, r);
  }
}

void backtrack(int *S, int *res, int s, int r, int k, int m, int n){
  res[k] = 1;
  if(s+S[k]==m){
    for(int i=0; i<=k; i++){
      if(res[i])
        cout << S[i] << " ";
    }
    cout << endl;
  }
  else if(s+S[k]+S[k+1]<=m)
    backtrack(S, res, s+S[k], r-S[k], k+1, m, n);
  if((s+r-S[k]>=m) && (s+S[k+1]<=m)){
    res[k] = 0;
    backtrack(S, res, s, r-S[k], k+1, m, n);
  }
}

int main(){
  int m, n;
  cin >> m >> n;
  int *S = new int[n];
  for(int i=0; i<n; i++)
    cin >> S[i];
  int *res = new int[n];
  memset(res, 0, sizeof(res));
  int s = 0;
  int r = 0;
  for(int i=0; i<n; i++)
    r += S[i];
  sort(S, 0, n-1);

}