// Fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int weight;
	int profit;
};

void swap(Item &a, Item &b);

int partition(Item arr[], int low, int high) {
	int pivot = arr[high].weight;
	int i = low - 1;
	for(int j = low; j < high; j++) {
		if(arr[j].weight < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}


void swap(Item &a, Item &b) {
	Item temp = a;
	a = b;
	b = temp;
}

void quickSort(Item arr[], int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

double fractionalKnapsack(int capacity, Item items[], int n) {
	// Strategy 2: Items arranged by their weight values
	quickSort(items, 0, n-1);
	int currentWeight = 0;
	double totalProfit = 0.0;
	for(int i=0; i<n; i++) {
		if(currentWeight + items[i].weight <= capacity) {
			currentWeight += items[i].weight;
			totalProfit += items[i].profit;
		}
		else {
			int remainingWeight = capacity - currentWeight;
			totalProfit += items[i].profit * ((double)remainingWeight / items[i].weight);
			break;
		}
	}
	return totalProfit;
}

int main() {
	int capacity;
	cout << "Enter the capacity of the knapsack: ";
	cin >> capacity;
	int n;
	cout << "Enter the no of items: ";
	cin >> n;
	Item items[n];
	for(int i=0; i<n; i++) {
		cout << "Enter the weight of item " << i+1 << ": ";
		cin >> items[i].weight;
		cout << "Enter the profit of item " << i+1 << ": ";
		cin >> items[i].profit;
	}
	cout << fractionalKnapsack(capacity, items, n) << endl;
	return 0;
}

// Input and Output
// Enter the capacity of the knapsack: 15
// Enter the no of items: 7
// Enter the weight of item 1: 1
// Enter the profit of item 1: 5
// Enter the weight of item 2: 3
// Enter the profit of item 2: 10
// Enter the weight of item 3: 5
// Enter the profit of item 3: 15
// Enter the weight of item 4: 4
// Enter the profit of item 4: 7
// Enter the weight of item 5: 1
// Enter the profit of item 5: 8
// Enter the weight of item 6: 3
// Enter the profit of item 6: 9
// Enter the weight of item 7: 2
// Enter the profit of item 7: 4
// 46