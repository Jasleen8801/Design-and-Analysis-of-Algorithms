#include <bits/stdc++.h>
using namespace std;

struct Item{
	string name;
  int weight;
	int profit;
	double ratio;
};

void swap(Item &a, Item &b){
	Item temp = a;
	a = b;
	b = temp;
}

int partition(Item arr[], int l, int r){
	double pivot = arr[r].ratio;
	int i = l-1;
	for(int j=l; j<r; j++){
		if(arr[j].ratio > pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}

void quickSort(Item arr[], int l, int r){
	if(l < r){
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, r);
	}
}

double fractionalKnapsack(int C, Item items[], int n){
	quickSort(items, 0, n-1);
	int currWt = 0;
	double ans = 0.0;
	for(int i=0; i<n; i++){
		if(currWt + items[i].weight <= C){
			currWt += items[i].weight;
			ans += items[i].profit;
			cout << items[i].name << " added completely." << endl;
		}
		else{
			int remWt = C - currWt;
			ans += items[i].profit * ((double)remWt / items[i].weight);
			cout << items[i].name << " added partially." << endl;
			break;
		}
	}
	return ans;
}

int main() {
	int n, C;
	cout << "Enter the number of items and capacity of knapsack: ";
	cin >> n >> C;
	Item items[n];
	for(int i=0; i<n; i++){
		cout << "Enter the weight and profit of item " << i+1 << ": ";
		cin >> items[i].weight >> items[i].profit;
		items[i].ratio = (double)items[i].profit / items[i].weight;
		items[i].name = "Item " + to_string(i+1);
	}
	cout << fractionalKnapsack(C, items, n) << " is the maximum profit" << endl;
	return 0;
}