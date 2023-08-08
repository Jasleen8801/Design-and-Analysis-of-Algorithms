// Provided some data values and converting it into maxheap

#include <bits/stdc++.h>
using namespace std;

void siftdown(int v[], int i, int n);

void buildMaxHeap(int v[], int n){
    for(int i=n/2; i>=1; i--){
        siftdown(v, i, n);
    }
}

void siftdown(int v[], int i, int n){
    int temp = v[i];
    while(2*i <= n){
        int child = 2*i;
        // if right child bigger than left child
        if(child<n && v[child+1]>v[child]){
            child++;
        } 
        if(v[child] > temp) v[i]=v[child];
        else break;
        i = child;
    }
    v[i] = temp;
}

void heapSort(int v[], int n){
    buildMaxHeap(v, n);
    while(n>0){
        swap(v[1],v[n]);
        n--;
        siftdown(v, 1, n);
    }
}

int main(){
    int n = 13;
    int v[] = {0, 104, 71, 23, 66, 27, 24, 8, 5, 32, 25, 18, 22};
    buildMaxHeap(v, n);
    for(int i=1; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// output: 104 71 24 66 27 23 8 5 32 25 18 22 