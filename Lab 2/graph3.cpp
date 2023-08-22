#include <bits/stdc++.h>
using namespace std;

// DFS traversal (continuation of graph1.cpp)

// 6. Initialize all the nodes to ready mode
// 7. Get the start vertex to sv (from 1 to n)
// 8. Put sv to the stack S and change the status of sv to waiting (status[sv] = 2)
// 9. while S is not empty
// 	9.1 V = S[top--] Get the vertex from the top of stack
// 	9.2 status[V] = 3 (processed)
// 	9.3 print V
// 10. for all neighbours of V, do the following:
// 	10.1 put all those neighbours of V which are in ready mode to the stack S and change their status to waiting
// 				for i = 1 to n
// 					if A[V][i] != 0 and status[i] == 1
// 						S[++top] = i
// 	10.2 status[neighbour] = 2
// 						status[i] = 2

class Stack {
public:
	int top;
	int size;
	int *S;

	Stack() {
		top = -1;
		size = 10;
		S = new int[size];
	}

	Stack(int size) {
		top = -1;
		this->size = size;
		S = new int[this->size];
	}

	void push(int x) {
		if(top == size-1)
			cout << "Stack overflow" << endl;
		else {
			top++;
			S[top] = x;
		}
	}

	bool isEmpty() {
		return top == -1;
	}

	int pop() {
		int x = -1;
		if(top == -1)
			cout << "Stack underflow" << endl;
		else {
			x = S[top];
			top--;
		}
		return x;
	}

	int peek(int index) {
		int x = -1;
		if(top-index+1 < 0)
			cout << "Invalid index" << endl;
		else
			x = S[top-index+1];
		return x;
	}

	int stackTop() {
		if(top == -1)
			return -1;
		else
			return S[top];
	}

	void display() {
		for(int i=top; i>=0; i--)
			cout << S[i] << " | ";
		cout << endl;
	}
};

int main() {
	int n;
	cout << "Enter the no of vertices: ";
	cin >> n;
	int A[n][n];
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			A[i][j] = 0;
	int Ed;
	cout << "Enter the no of edges: ";
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

	int status[n];
	for(int i=0; i<n; i++)
		status[i] = 1;

	Stack s(n);
	int sv;
	cout << "Enter the start vertex: ";
	cin >> sv;
	s.push(sv);
	status[sv] = 2;
	while(!s.isEmpty()) {
		int V = s.pop();
		status[V] = 3;
		cout << V << " ";
		for(int i=0; i<n; i++) {
			if(A[V][i] != 0 && status[i] == 1) {
				s.push(i);
				status[i] = 2;
			}
		}
	}
	s.display();
	return 0;
}