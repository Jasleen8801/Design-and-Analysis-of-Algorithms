#include <bits/stdc++.h>
using namespace std;

void printOptimalParenthesis(int S[][101], int i, int j) {
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		printOptimalParenthesis(S, i, S[i][j]);
		printOptimalParenthesis(S, S[i][j] + 1, j);
		cout << ")";
	}
}

int main(){
	int n;
	cout << "Enter number of matrices: ";
	cin >> n;
	int d[n + 1];
	for (int i = 0; i < n; i++){
		int x, y;
		cout << "Enter dimension of matrix " << i + 1 << ": ";
		cin >> x >> y;
		d[i] = x;
		if (i == n - 1) 
			d[i + 1] = y;
	}
	int M[101][101]; // M[i][j] = minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]
	int S[101][101]; // S[i][j] = index of the matrix after which the product is split in the minimum number of scalar multiplications needed to compute the matrix A[i]A[i+1]...A[j]

	for (int i = 1; i <= n; i++)
		M[i][i] = 0;

	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n - i + 1; j++){
			int l = j + i - 1;
			M[j][l] = INT_MAX;
			for (int k = j; k < l; k++){
				int cost = M[j][k] + M[k + 1][l] + d[j - 1] * d[k] * d[l];
				if (cost < M[j][l]){
					M[j][l] = cost;
					S[j][l] = k;
				}
			}
		}
	}

	cout << "Minimum number of scalar multiplications needed: " << M[1][n] << endl;

	cout << "M matrix: " << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}

	cout << "S matrix: " << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << S[i][j] << " ";
		cout << endl;
	}

	cout << "Optimal parenthesization: ";
	printOptimalParenthesis(S, 1, n);
	// TODO: Print the optimal parenthesization
	return 0;
}
