// Job Sequencing

#include <bits/stdc++.h>
using namespace std;

struct Job {
  int deadline;
  int profit;
  string id;
};

int partition(Job arr[], int p, int r){
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(arr[j].profit > arr[r].profit){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quickSort(Job arr[], int p, int r){
  if(p < r){
    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
  }
}

int main(){
  int n;
  cin >> n;
  Job arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i].deadline >> arr[i].profit;
    arr[i].id = to_string(i+1);
  }
  quickSort(arr, 0, n-1);
  int maxDeadline = 0;
  for(int i=0; i<n; i++)
    if(arr[i].deadline > maxDeadline)
      maxDeadline = arr[i].deadline;
  bool slots[maxDeadline+1] = {false};
  for(int i=0; i<n; i++){ 
    for(int j=min(maxDeadline, arr[i].deadline); j>=1; j--){ 
      if(slots[j] == false){
        slots[j] = true;
        cout << arr[i].id << " ";
        break;
      }
    }
  }
  cout << endl;
  return 0;
}

/*
Input:

4
2 100
1 10
2 15
1 27
*/