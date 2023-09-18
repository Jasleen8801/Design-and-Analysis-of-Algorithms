#include <bits/stdc++.h>
using namespace std;

int MFR(vector<int> &res, int n); 

int fib1(int n) {
	if (n <= 1) return n;
	return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	int f_twoback = 1;
	int f_oneback = 1;
	for (int i = 3; i <= n; i++) {
		int f_current = f_twoback + f_oneback;
		f_twoback = f_oneback;
		f_oneback = f_current;
	}
	return f_oneback;
}

int fib3(int n) {
	vector<int> res(n+1, -1);
	return MFR(res, n);
}

int MFR(vector<int> &res, int n) {
	if (res[n] != -1) return res[n];
	if (n == 1) return 1;
	if (n == 2) return 1;
	res[n] = MFR(res, n - 1) + MFR(res, n - 2);
	return res[n];
}

int main() {
	int n;
	cin >> n;
	cout << "Using recursion: " << endl;
	cout << fib1(n) << endl;
	cout << "Using iteration: " << endl;
	cout << fib2(n) << endl;
	cout << "Using memoization: " << endl;
	cout << fib3(n) << endl;
	return 0;
}
