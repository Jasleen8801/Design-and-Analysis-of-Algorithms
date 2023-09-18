#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
	vector<int> heap;
public:
	MaxHeap(int capacity){
		heap.resize(capacity);
	}
	void insert(int val){
		heap.push_back(val);
		int parent_idx = (heap.size()-2)/2;
		int child_idx = heap.size()-1;
		while(parent_idx>0 && heap[parent_idx]<heap[child_idx]){
			swap(heap[parent_idx], heap[child_idx]);
			child_idx = parent_idx;
			parent_idx = (child_idx-1)/2;
		}
		cout << "Inserted " << val << endl;
	}

	int deleteMax(){
		if(heap.size()==0) return -1;
		int max = heap[0];
		int rightmost = heap[heap.size()-1];
		swap(max, rightmost);
		heap.pop_back();
		int parent_idx = 0;
		int left_child_idx = 2*parent_idx+1;
		int right_child_idx = 2*parent_idx+2;
		while(left_child_idx<heap.size() && right_child_idx<heap.size() && (heap[parent_idx]<heap[left_child_idx] || heap[parent_idx]<heap[right_child_idx])){
			if(heap[left_child_idx]>heap[right_child_idx]){
				swap(heap[parent_idx], heap[left_child_idx]);
				parent_idx = left_child_idx;
			}
			else{
				swap(heap[parent_idx], heap[right_child_idx]);
				parent_idx = right_child_idx;
			}
		}
		return max;
	}

	void print(){
		for(int i=0;i<heap.size();i++){
			cout << heap[i] << " ";
		}
		cout << endl;
	}

	void heapify(int arr[], int n){
		for(int i=0;i<n;i++){
			heap.push_back(arr[i]);
		}
		for(int i=heap.size()-1;i>=0;i--){
			int parent_idx = (i-1)/2;
			int left_child_idx = 2*parent_idx+1;
			int right_child_idx = 2*parent_idx+2;
			while(left_child_idx<heap.size() && right_child_idx<heap.size() && (heap[parent_idx]<heap[left_child_idx] || heap[parent_idx]<heap[right_child_idx])){
				if(heap[left_child_idx]>heap[right_child_idx]){
					swap(heap[parent_idx], heap[left_child_idx]);
					parent_idx = left_child_idx;
				}
				else{
					swap(heap[parent_idx], heap[right_child_idx]);
					parent_idx = right_child_idx;
				}
			}
		}
	}
};

int main(){
	MaxHeap heap(10);
	heap.insert(10);
	heap.insert(20);
	heap.insert(30);
	heap.insert(40);
	heap.insert(50);
	heap.insert(60);
	heap.insert(70);
	heap.insert(80);
	heap.insert(90);
	heap.insert(100);
	heap.print();
	cout << heap.deleteMax() << endl;
	heap.print();
	cout << heap.deleteMax() << endl;
	heap.print();
	cout << heap.deleteMax() << endl;
	heap.print();
	cout << heap.deleteMax() << endl;
	heap.print();
	heap.heapify(new int[10]{10,20,30,40,50,60,70,80,90,100}, 10);
	heap.print();
	return 0;
}