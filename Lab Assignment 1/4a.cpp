// WAP to implement Merging of two arrays containing sorted data

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int res[]){
    int i=0, j=0, k=0;

    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]) res[k++] = arr1[i++];
        else res[k++] = arr2[j++];
    }

    while(i<n1) res[k++] = arr1[i++];
    while(j<n2) res[k++] = arr2[j++];
}

int main() {
    int n1, n2;
    cout << "Enter size of 1st sorted array: ";
    cin >> n1;

    int *arr1 = new int[n1];
    cout << "Enter elements for arr1: " << endl;
    for(int i=0; i<n1; i++) cin >> arr1[i];

    cout << "Enter size of 2nd sorted array: ";
    cin >> n2;

    int *arr2 = new int[n2];
    cout << "Enter elements for arr2: " << endl;
    for(int i=0; i<n2; i++) cin >> arr2[i];

    int n = n1 + n2;
    int *res = new int[n];

    mergeArrays(arr1, n1, arr2, n2, res);

    cout << "Merged and sorted array: ";
    for(int i=0; i<n; i++) cout << res[i] << " ";
    cout << endl;

    return 0;
}