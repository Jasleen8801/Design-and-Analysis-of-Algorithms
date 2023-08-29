// Fibonacci sequence

#include <bits/stdc++.h>
using namespace std;

int fib1(int n) {
	// Time complexity: O(2^n)
	if(n <= 1) {
		return n;
	}
	return fib1(n-1) + fib1(n-2);
}

int fib2(int n) {
	// Time complexity: O(n)
	int f[n+1];
	f[0] = 0;
	f[1] = 1;
	for(int i=2; i<=n; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int MFR(int result[], int n){
	if(result[n]!=-1) return result[n];
	if(n<=1) result[n] = n;
	else result[n] = MFR(result, n-1) + MFR(result, n-2);
}

int fib3(int n) {
	// Time complexity: O(logn)
	int result[n];
	for(int i=0; i<n; i++) result[i] = -1;
	return MFR(result, n);
}

int main() {
	int n;
	cin >> n;
	cout << fib1(n) << endl;
	cout << fib2(n) << endl;
	cout << fib3(n) << endl;
	return 0;
}