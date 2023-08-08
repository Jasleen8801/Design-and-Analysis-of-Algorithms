// WAP to implement - Find the frequency of occurrence one number in a data set.

#include <bits/stdc++.h>
using namespace std;

int findFrequency1(int arr[], int n, int x){
    int freq = 0;
    for(int i=0; i<n; i++) 
        if(arr[i] == x)
            freq++;
    return freq;
}

int findFrequency2(int arr[], int n, int x) {
    unordered_map<int, int> freqMap;
    for(int i=0; i<n; i++) freqMap[arr[i]]++;
    return freqMap[x];
}

int main() {
    int n; 
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements of dataset: " << endl;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int x;
    cout << "Enter the number to find its frequency: ";
    cin >> x;

    cout << "Frequency of " << x << " is " << findFrequency1(arr, n, x) << endl;
    return 0;
}