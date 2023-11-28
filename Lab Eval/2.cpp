// Fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
  int profit;
  int ratio;
  string id;
};

int partition(Item arr[], int p, int r){
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(arr[j].ratio > arr[r].ratio){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quickSort(Item arr[], int p, int r){
  if(p < r){
    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
  }
}

int main(){
  int n;
  cin >> n;
  Item arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i].profit >> arr[i].weight;
    arr[i].ratio = arr[i].profit / arr[i].weight;
    arr[i].id = to_string(i+1);
  }
  quickSort(arr, 0, n-1);
  int capacity;
  cin >> capacity;
  int currWt = 0;
  double totalProfit = 0;
  for(int i=0; i<n; i++){
    if(currWt + arr[i].weight <= capacity){
      currWt += arr[i].weight;
      totalProfit += arr[i].profit;
    } else {
      int remWt = capacity - currWt;
      totalProfit += arr[i].profit * ((double)remWt / arr[i].weight);
      break;
    }
  }
  cout << totalProfit << endl;
  return 0;
}

/*
Input:
7
5 1
10 3
15 5
7 4
8 1
9 3
4 2
15
*/