// Write a program to Implement Quick sort. Also analyze your program.

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int h){
    int p = arr[h];
    int i = l - 1;

    for(int j=l; j<h; j++){
        if(arr[j] <= p){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[h]);
    return i+1;
}

void quicksort(int arr[], int l, int h){
    if(l<h){
        int pIdx = partition(arr, l, h);
        quicksort(arr, l, pIdx-1);
        quicksort(arr, pIdx+1, h);
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements of array: " << endl;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    quicksort(arr, 0, n-1);

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}