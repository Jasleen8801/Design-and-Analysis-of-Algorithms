// Activity Selection Problem

#include <bits/stdc++.h>
using namespace std;

struct Activity {
	int start;
	int finish;
	string name;
};

void swap(Activity &a, Activity &b);

int partition(Activity arr[], int low, int high) {
	int pivot = arr[high].finish;
	int i = low-1;
	for(int j=low; j<high; j++) {
		if(arr[j].finish < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void swap(Activity &a, Activity &b) {
	Activity temp = a;
	a = b;
	b = temp;
}

void quickSort(Activity arr[], int low, int high) {
	if(low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
	}
}

void activitySelection(Activity activities[], int n){
	quickSort(activities, 0, n-1);
	Activity select_act = activities[0];
	Activity solution[n];
	solution[0] = select_act;
	int j=1;
	for(int i=1; i<n; i++){
		if(activities[i].start >= select_act.finish) {
			solution[j] = activities[i];
			select_act = activities[i];
			j++;
		}
	}
	cout << "Selected Activities: ";
	for(int i=0; i<j; i++) {
		cout << solution[i].name << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "Enter number of activities: ";
	cin >> n;
	Activity activities[n];
	for(int i=0; i<n; i++) {
		cout << "Enter start of activity " << i+1 << ": ";
		cin >> activities[i].start;
		cout << "Enter finish of activity " << i+1 << ": ";
		cin >> activities[i].finish;
		cout << "Enter name of activity " << i+1 << ": ";
		cin >> activities[i].name;
	}
	activitySelection(activities, n);
	return 0;
}

// Input and Output
/*Enter number of activities: 6
Enter start of activity 1: 4
Enter finish of activity 1: 8
Enter name of activity 1: J1
Enter start of activity 2: 1
Enter finish of activity 2: 2
Enter name of activity 2: J2
Enter start of activity 3: 2
Enter finish of activity 3: 3
Enter name of activity 3: J3
Enter start of activity 4: 0
Enter finish of activity 4: 5
Enter name of activity 4: J4
Enter start of activity 5: 4
Enter finish of activity 5: 6
Enter name of activity 5: J5
Enter start of activity 6: 7
Enter finish of activity 6: 8
Enter name of activity 6: J6
Selected Activities: J2 J3 J5 J6 */