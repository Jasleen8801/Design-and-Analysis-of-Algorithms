// Travelling Salesman Problem - Branch and Bound

#include <bits/stdc++.h>
using namespace std;

void reduceMatrix(int **cost, int n, int *rowMin){
  for(int i = 0; i < n; i++){
    rowMin[i] = INT_MAX;
    for(int j = 0; j < n; j++)
      if(cost[i][j] < rowMin[i])
        rowMin[i] = cost[i][j];
    for(int j = 0; j < n; j++)
      if(cost[i][j] != INT_MAX)
        cost[i][j] -= rowMin[i];
  }
}

void reduceMatrixCol(int **cost, int n, int *colMin){
  for(int i = 0; i < n; i++){
    colMin[i] = INT_MAX;
    for(int j = 0; j < n; j++)
      if(cost[j][i] < colMin[i])
        colMin[i] = cost[j][i];
    for(int j = 0; j < n; j++)
      if(cost[j][i] != INT_MAX)
        cost[j][i] -= colMin[i];
  } 
}

int calcReducedCost(int i, int j, int** cost, int *rowMin, int *colMin){
  return cost[i][j] + rowMin[i] + colMin[j]; // reduced cost = cost + rowMin + colMin
}

void TSPBranchAndBound(int **cost, int n){
  int *rowMin = new int[n];
  int *colMin = new int[n];

  reduceMatrix(cost, n, rowMin); 
  reduceMatrixCol(cost, n, colMin);

  int *path = new int[n]; // path[i] = j means ith city is connected to jth city
  memset(path, -1, sizeof(path)); // -1 means not connected to any city
  path[0] = 0; // starting from 0th city
  int currBound = 0; // current lower bound means current cost
  int finalCost = INT_MAX; // final cost

  while(true){
    int i; // current path length
    for(i = 0; i < n; i++)
      if(path[i] == -1)
        break;
    if(i == n){
      int currCost = 0; // current cost
      for(int i = 0; i < n; i++)
        currCost += cost[path[i]][path[i+1]]; // calculating cost of current path
      currCost += cost[path[n-1]][path[0]]; // adding cost of last city to first city
      if(currCost < finalCost) // if current cost is less than final cost
        finalCost = currCost; // update final cost
      continue;
    }
    for(int j=0; j<n; j++){ // for each city
      if(cost[path[i-1]][j] == 0 && i == n-1) // if last city is connected to current city
        continue;
      if(path[i] == -1){ // if current city is not connected to any city
        int tempBound = currBound; // store current cost
        currBound += calcReducedCost(i-1, j, cost, rowMin, colMin); // add cost of current city
        if(currBound < finalCost){ 
          path[i] = j; // connect current city to jth city
          TSPBranchAndBound(cost, n); // call TSPBranchAndBound for next city
        }
        currBound = tempBound; // restore current cost
        memset(path, -1, sizeof(path)); // reset path
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  int **cost = new int*[n];
  for(int i = 0; i < n; i++){
    cost[i] = new int[n];
    for(int j = 0; j < n; j++)
      cin >> cost[i][j];
  }
  TSPBranchAndBound(cost, n);
  return 0;
}