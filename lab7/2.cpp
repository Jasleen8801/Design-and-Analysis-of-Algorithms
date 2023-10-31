// Subset Sum

#include <bits/stdc++.h>
using namespace std;

void quicksort(int arr[], int l, int r){
  if(l<r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++){
      if(arr[j]<pivot){
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i+1], arr[r]);
    quicksort(arr, l, i);
    quicksort(arr, i+2, r);
  }
}

void backtrack(int arr[], int target, int ans[], int s, int r, int k){
  ans[k] = 1;
  if(s+arr[k]==target){
    for(int i=0; i<=k; i++){
      if(ans[i])
        cout << arr[i] << " ";
    }
    cout << endl;
  }
  else if(s+arr[k]+arr[k+1]<=target)
    backtrack(arr, target, ans, s+arr[k], r-arr[k], k+1);
  if((s+r-arr[k]>=target) && (s+arr[k+1]<=target)){
    ans[k] = 0;
    backtrack(arr, target, ans, s, r-arr[k], k+1);
  }
}

int main(){
  int n, target;
  cin >> n >> target;
  int arr[n];
  for(int i=0; i<n; i++)
    cin >> arr[i];
  int ans[n];
  memset(ans, 0, sizeof(ans));
  int s = 0; //sum of elements in ans
  int r = 0; //remaining sum
  for(int i=0; i<n; i++)
    r += arr[i];
  quicksort(arr, 0, n-1);
  backtrack(arr, target, ans, s, r, 0);
  return 0;
}