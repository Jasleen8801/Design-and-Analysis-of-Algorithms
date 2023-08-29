#include <bits/stdc++.h>
using namespace std;

// BFS traversal (continuation of graph1.cpp)
// Problems - no fixed starting node
// 					- too many successors
// 					- too many predecessors
// Node types - Ready, waiting, processed
// For BFS we use queue (array)
// We have a status array from 1 to n (initially status of nodes - 1)

// 6. Initialize all the nodes to ready mode
// 7. Get the start vertex to sv (from 1 to n)
// 8. Put sv to the queue Q and change the status of sv to waiting (status[sv] = 2)
// 9. while Q is not empty
// 	9.1 V = Q[F++] Get the vertex from the front side of queue
// 	9.2 status[V] = 3 (processed)
// 	9.3 print V
// 10. for all neighbours of V, do the following:
// 	10.1 put all those neighbours of V which are in ready mode to the queue Q and change their status to waiting
// 				for i = 1 to n
// 					if A[V][i] != 0 and status[i] == 1
// 						Q[R++] = i
// 	10.2 status[neighbour] = 2
// 						status[i] = 2

class Queue {
public:
	int front, rear;
	int size;
	int *Q;

	Queue() {
		front = rear = -1;
		size = 10;
		Q = new int[size];
	}
	
	Queue(int size) {
		front = rear = -1;
		this->size = size;
		Q = new int[this->size];
	}

	void enqueue(int x) {
		if(rear == size-1)
			cout << "Queue is full" << endl;
		else {
			rear++;
			Q[rear] = x;
		}
	}

	bool isEmpty() {
		return front == rear;
	}

	int dequeue() {
		int x = -1;
		if(front == rear)
			cout << "Queue is empty" << endl;
		else {
			front++;
			x = Q[front];
		}
		return x;
	}

	void display() {
		for(int i=front+1; i<=rear; i++)
			cout << Q[i] << " ";
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
	// cout << "Adjacency Matrix: " << endl;
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) 
	// 		cout << A[i][j] << " ";
	// 	cout << endl;
	// }

	int status[n];
	for(int i=0; i<n; i++)
		status[i] = 1;
	
	Queue q(n);
	int sv;
	cout << "Enter the start vertex: ";
	cin >> sv;
	q.enqueue(sv);
	status[sv] = 2;
	while(!q.isEmpty()) {
		int v = q.dequeue();
		status[v] = 3;
		cout << v << " ";
		
		for(int i=0; i<n; i++) {
			if(A[v][i] != 0 && status[i] == 1) {
				q.enqueue(i);
				status[i] = 2;
			} 
		}
	}

	q.display();
	return 0;
}

// Input Test Case:
// Vertices: 0, 1, 2, 3, 4
// Edges: (0, 1), (0, 2), (1, 3), (1, 4), (2, 4), (3, 4)

// Test Case:

// Enter the number of vertices: 5
// Enter the number of edges: 6
// Enter the source vertex: 0
// Enter the end vertex: 1
// Enter the source vertex: 0
// Enter the end vertex: 2
// Enter the source vertex: 1
// Enter the end vertex: 3
// Enter the source vertex: 1
// Enter the end vertex: 4
// Enter the source vertex: 2
// Enter the end vertex: 4
// Enter the source vertex: 3
// Enter the end vertex: 4
// Enter the start vertex: 0