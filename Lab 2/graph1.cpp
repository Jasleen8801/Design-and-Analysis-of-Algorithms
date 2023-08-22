#include <bits/stdc++.h>
using namespace std;

// Algorithm
// 1. Get n - no of vertices (user input)
// 2. A[n][n] - adjacency matrix (user input)
// 3. for i = 1 to n
//      for j = 1 to n
//        A[i][j] = 0
// 4. Get the no of edges - Ed (user input)
// 5. for i = 1 to Ed
//  5.1 Get sv - source vertex (user input)
//	5.2 Get ev - end vertex (user input)
//	5.3 A[sv][ev] = 1
// 6. for i = 1 to n
//      for j = 1 to n
//        print A[i][j]

int main() {
	int n;
	cout << "Enter the no of vertices: ";
	cin >> n;
	int A[n][n];
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			A[i][j] = 0;
	cout << "Enter the no of edges: ";
	int Ed;
	cin >> Ed;
	for(int i=0; i<Ed; i++){
		int sv, ev;
		cout << "Enter the source vertex: ";
		cin >> sv;
		cout << "Enter the end vertex: ";
		cin >> ev;
		A[sv][ev] = 1;
	}
	cout << "Adjacency Matrix: " << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) 
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}