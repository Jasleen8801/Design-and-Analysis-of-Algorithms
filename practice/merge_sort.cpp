// Merge Sort

#include <bits/stdc++.h>
using namespace std;

void merge(int left[], int right[], int arr[]){
	int nL = sizeof(left)/sizeof(left[0]);
	int nR = sizeof(right)/sizeof(right[0]);
	int i=0, j=0, k=0;
	while(i<nL && j<nR){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<nL){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<nR){
		arr[k] = right[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[]){
	int n = sizeof(arr)/sizeof(arr[0]);
	if(n < 2) return;
	int mid = n/2;
	int left[mid], right[n-mid];
	for(int i=0; i<mid; i++){
		left[i] = arr[i];
	}
	for(int i=mid; i<n; i++){
		right[i-mid] = arr[i];
	}
	merge_sort(left);
	merge_sort(right);
	merge(left, right, arr);
}

