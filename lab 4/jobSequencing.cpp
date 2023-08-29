#include <bits/stdc++.h>
using namespace std;

struct Job{
	string name;
	int d;
	int p;
};

void swap(Job &a, Job &b){
	Job temp = a;
	a = b;
	b = temp;
}

int partition(Job arr[], int l, int r){
	int pivot = arr[r].p;
	int i = l-1;
	for(int j=l; j<r; j++){
		if(arr[j].p > pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}

void quickSort(Job arr[], int l, int r){
	if(l < r){
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, r);
	}
}

void jobSequencing(Job jobs[], int n) {
	quickSort(jobs, 0, n-1);
	cout << "Sorted Jobs in decreasing order of profit: ";
	for(int i=0; i<n; i++)
		cout << jobs[i].name << " ";
	int md = 0;
	for(int i=0; i<n; i++)
		if(jobs[i].d > md)
			md = jobs[i].d;
	bool slots[md+1] = {false};
	cout << "Job sequence: ";
	int profit = 0;
	for(int i=0; i<n; i++)
		for(int j=min(md, jobs[i].d); j>=1; j--)
			if(!slots[j]){
				slots[j] = true;
				profit += jobs[i].p;
				cout << jobs[i].name << " ";
				break;
			}
	cout << endl << "Total profit: " << profit << endl;
}

int main() {
	int n;
	cout << "Enter the number of jobs: ";
	cin >> n;
	Job jobs[n];
	for(int i=0; i<n; i++){
		cout << "Enter the deadline and profit of job " << i+1 << ": ";
		cin >> jobs[i].d >> jobs[i].p;
		jobs[i].name = "J" + to_string(i+1);
	}
	jobSequencing(jobs, n);
	return 0;
}