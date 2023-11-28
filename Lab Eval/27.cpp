// 0/1 Knapsack - Branch and Bound

#include <bits/stdc++.h>
using namespace std;

int partition(double *arr, int p, int r){
  int i = p-1;
  for(int j=p; j<r; j++){
    if(arr[j] <= arr[r]){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quickSort(double *arr, int p, int r){
  if(p<r){
    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
  }
}

struct Item {
  int value;
  int weight;
};

class KnapsackNode {
public:
  int* items;
  int value;
  int weight;

  KnapsackNode(int* items, int value, int weight) {
    this->items = items;
    this->value = value;
    this->weight = weight;
  }
};

class Knapsack {
public:
  int maxWeight;
  Item *items;

  Knapsack(int maxWeight, Item *items) {
    this->maxWeight = maxWeight;
    this->items = items;
  }

  int solve(){
    double *ratios = new double[maxWeight];
    for(int i=0; i<maxWeight; i++)
      ratios[i] = (double)items[i].value / items[i].weight;
    quickSort(ratios, 0, maxWeight-1);
    int bestVal = 0;
    queue<KnapsackNode> q;
    q.push(KnapsackNode(new int[maxWeight], 0, 0));
    while(!q.empty()){
      KnapsackNode node = q.front();
      q.pop();
      int *items = node.items;
      int i = sizeof(items)/sizeof(items[0]);
      int j = sizeof(this->items)/sizeof(this->items[0]);
      if(i == j){
        bestVal = max(bestVal, node.value);
      } else {
        Item item = this->items[i];
        KnapsackNode withItem(node.items, node.value + item.value, node.weight + item.weight);
        if(isPromising(withItem, this->maxWeight, bestVal))
          q.push(withItem);
        KnapsackNode withoutItem(node.items, node.value, node.weight);
        if(isPromising(withoutItem, this->maxWeight, bestVal))
          q.push(withoutItem);
      }
    }
    return bestVal;
  }

  bool isPromising(KnapsackNode node, int maxWeight, int bestVal){
    return node.weight <= maxWeight && node.value + getBound(node) > bestVal;
  }

  int getBound(KnapsackNode node){
    int remWt = this->maxWeight - node.weight;
    int bound = node.value;
    int i = sizeof(node.items)/sizeof(node.items[0]);
    while(i < sizeof(this->items)/sizeof(this->items[0]) && remWt > 0){
      if(this->items[i].weight <= remWt){
        bound += this->items[i].value;
        remWt -= this->items[i].weight;
      } else {
        bound += this->items[i].value * ((double)remWt / this->items[i].weight);
        remWt = 0;
      }
      i++;
    }
    return bound;
  }
};

int main(){
  int n, maxWeight;
  cin >> n >> maxWeight;
  Item *items = new Item[n];
  for(int i=0; i<n; i++)
    cin >> items[i].value >> items[i].weight;
  Knapsack knapsack(maxWeight, items);
  cout << knapsack.solve() << endl;
  return 0;
}