// Job Sequencing Problem

#include <bits/stdc++.h>
using namespace std;

struct Job {
	int deadline;
	int profit;
	string name;
};

void swap(Job &a, Job &b);

int partition(Job arr[], int low, int high) {
	int pivot = arr[high].profit;
	int i = low-1;
	for(int j=low; j<high; j++) {
		if(arr[j].profit > pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void swap(Job &a, Job &b) {
	Job temp = a;
	a = b;
	b = temp;
}

void quickSort(Job arr[], int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void jobSequencing(Job jobs[], int n) {
	quickSort(jobs, 0, n-1);
	int max_deadline = 0;
	for(int i=0; i<n; i++) {
		if(jobs[i].deadline > max_deadline) {
			max_deadline = jobs[i].deadline;
		}
	}
	bool slots[max_deadline+1] = {false};
	for(int i=0; i<n; i++){
		for(int j=min(max_deadline, jobs[i].deadline); j>=1; j--) {
			if(slots[j] == false) {
				slots[j] = true;
				cout << jobs[i].name << " ";
				break;
			}
		}
	}
}

int main() {
	int n;
	cout << "Enter number of jobs: ";
	cin >> n;
	Job jobs[n];
	for(int i=0; i<n; i++){
		cout << "Enter name of job " << i+1 << ": ";
		cin >> jobs[i].name;
		cout << "Enter deadline of job " << i+1 << ": ";
		cin >> jobs[i].deadline;
		cout << "Enter profit of job " << i+1 << ": ";
		cin >> jobs[i].profit;
	}
	jobSequencing(jobs, n);
}

/*Input and Output:
Enter number of jobs: 4
Enter name of job 1: J1
Enter deadline of job 1: 2
Enter profit of job 1: 100
Enter name of job 2: J2
Enter deadline of job 2: 1
Enter profit of job 2: 10
Enter name of job 3: J3
Enter deadline of job 3: 2
Enter profit of job 3: 15
Enter name of job 4: J4
Enter deadline of job 4: 1
Enter profit of job 4: 27
J1 J4*/