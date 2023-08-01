// Find the frequency of occurrence all the numbers present in a data set.

#include <bits/stdc++.h>
using namespace std;

struct NumInfo{
    int num;
    int freq;
    bool flag;
};

void findFrequencies(int arr[], int n, NumInfo info[]) {
    for(int i=0; i<n; i++) {
        if(info[i].flag) continue;

        int freq = 1;
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]) {
                freq++;
                info[j].flag = true;
            }
        }
        info[i].freq = freq;
    }
}

unordered_map<int, int> findFrequencies1(int arr[], int n) {
    unordered_map<int, int> freqMap;
    for(int i=0; i<n; i++) freqMap[arr[i]]++;
    return freqMap;
}

int main() {
    int n;
    cout << "Enter size of data set: ";
    cin >> n;

    int *arr = new int[n];
    NumInfo *info = new NumInfo[n];

    for(int i=0; i<n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];

        info[i].num = arr[i];
        info[i].freq = 0;
        info[i].flag = false;
    }

    findFrequencies(arr, n, info);

    cout << "Frequency of num in data set: " << endl;
    for(int i=0; i<n; i++) {
        if(!info[i].flag){
            cout << info[i].num << " occurs " << info[i].freq << " times." << endl;
        }
    }

    delete[] arr;
    delete[] info;

    return 0;
}