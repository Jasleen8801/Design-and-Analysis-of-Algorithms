// Activity Selection

#include <bits/stdc++.h>
using namespace std;

struct Activity {
  int st; // start time
  int ft; // finish time
  string id; // activity id
};

int partition(Activity arr[], int p, int r){
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(arr[j].ft < arr[r].ft){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quickSort(Activity arr[], int p, int r){
  if(p < r){
    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
  }
}

int main(){
  int n;
  cin >> n;
  Activity arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i].st >> arr[i].ft;
    arr[i].id = to_string(i+1);
  }
  quickSort(arr, 0, n-1);
  Activity ans[n+1];
  Activity temp = arr[0];
  ans[0] = arr[0];
  int k=1;
  for(int i=1; i<n; i++){
    if(arr[i].st >= temp.ft){
      ans[k] = arr[i];
      temp = arr[i];
      k++;
    }
  }
  for(int i=0; i<k; i++)
    cout << ans[i].id << " ";
  cout << endl;
  return 0;
}

/*
Input:
11
1 4
3 5
0 6
5 7
3 9
5 9
6 10
8 11
8 12
2 14
12 16
*/