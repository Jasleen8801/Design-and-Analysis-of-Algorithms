// WAP to implement Merge sort. Also analyze your program.

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int lSize = m-l+1;
    int rSize = r-m;

    int* lArr = new int[lSize];
    int* rArr = new int[rSize];

    for(int i=0; i<lSize; i++) lArr[i] = arr[l+i];
    for(int j=0; j<rSize; j++) rArr[j] = arr[m+1+j];

    int i=0, j=0, k=0;

    while (i<lSize && j<rSize) {
        if(lArr[i] <= rArr[j]) arr[k++] = lArr[i++];
        else arr[k++] = rArr[j++];
        
    }

    while(i < lSize) arr[k++] = lArr[i++];
    while(i < rSize) arr[k++] = rArr[j++];
    
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements of array: " << endl;
    for(int i=0; i<n; i++) cin >> arr[i];

    mergeSort(arr, 0, n-1);

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}