#include <iostream>

using namespace std;

int ary[10][10], comp[10], n, cost = 0;

int least(int c){
	int i, nc = 999;
	int min = 999, kmin;

	for (i = 0; i < n; i++){
		if ((ary[c][i] != 0) && (comp[i] == 0))
			if (ary[c][i] + ary[i][c] < min){
				min = ary[i][0] + ary[c][i];
				kmin = ary[c][i];
				nc = i;
			}
	}

	if (min != 999)
		cost += kmin;

	return nc;
}

void mincost(int city){
	int i, ncity;
	comp[city] = 1;

	cout << city + 1 << "--->";
	ncity = least(city);

	if (ncity == 999){
		ncity = 0;
		cout << ncity + 1;
		cost += ary[city][ncity];
		return;
	}
	mincost(ncity);
}

int main() {
	cout << "Enter the number of villages: ";
	cin >> n;

	cout << "\nEnter the Cost Matrix\n";
	for (int i = 0; i < n; i++){
		cout << "\nEnter Elements of Row: " << i + 1 << "\n";
		for (int j = 0; j < n; j++)
			cin >> ary[i][j];
		comp[i] = 0;
	}

	cout << "\n\nThe Path is:\n";
	mincost(0); 

	cout << "\n\nMinimum cost is " << cost;
	return 0;
}