#include <bits/stdc++.h>
using namespace std;

struct Item{
	int wt;
	int val;
	string id;
};

void greedy1(vector<Item>& items, int capacity){
	cout << "Greedy 1 by sorting according to value: ";
	sort(items.begin(), items.end(), [](Item a, Item b){
		return a.val>b.val;
	});
	int total_val = 0;
	for(int i=0;i<items.size();i++){
		if(capacity>=items[i].wt){
			total_val += items[i].val;
			capacity -= items[i].wt;
			cout << items[i].id << " ";
		}
	}
	cout << endl << "Total value: " << total_val << endl;
}

void greedy2(vector<Item>& items, int capacity){
	cout << "Greedy 2 by sorting according to weight: ";
	sort(items.begin(), items.end(), [](Item a, Item b){
		return a.wt<b.wt;
	});
	int total_val = 0;
	for(int i=0;i<items.size();i++){
		if(capacity>=items[i].wt){
			total_val += items[i].val;
			capacity -= items[i].wt;
			cout << items[i].id << " ";
		}
	}
	cout << endl << "Total value: " << total_val << endl;
}

void greedy3(vector<Item>& items, int capacity){
	cout << "Greedy 3 by sorting according to value/weight: ";
	sort(items.begin(), items.end(), [](Item a, Item b){
		return (double)a.val/a.wt>(double)b.val/b.wt;
	});
	int total_val = 0;
	for(int i=0;i<items.size();i++){
		if(capacity>=items[i].wt){
			total_val += items[i].val;
			capacity -= items[i].wt;
			cout << items[i].id << " ";
		}
	}
	cout << endl << "Total value: " << total_val << endl;
}

int main(){
	int n, capacity;
	cout << "Enter number of items: ";
	cin >> n;
	cout << "Enter capacity of knapsack: ";
	cin >> capacity;
	vector<Item> items(n);
	for(int i=0;i<n;i++){
		cout << "Enter weight and value of item " << i+1 << ": ";
		cin >> items[i].wt >> items[i].val;
		items[i].id = "Item " + to_string(i+1);
	}
	greedy1(items, capacity);
	greedy2(items, capacity);
	greedy3(items, capacity);
	return 0;
}