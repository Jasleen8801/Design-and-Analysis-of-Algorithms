// Quick Sort

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int r){
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(arr[j] <= arr[r]){ // arr[r] is pivot
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quick_sort(int arr[], int p, int r){
  if(p < r){
    int q = partition(arr, p, r);
    quick_sort(arr, p, q-1);
    quick_sort(arr, q+1, r);
  }
}

int main(){
  int arr[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  quick_sort(arr, 0, n-1);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}