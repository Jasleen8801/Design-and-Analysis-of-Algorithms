#include <bits/stdc++.h>
using namespace std;

int algo_dp_helper(vector<int>& d, vector<vector<int>>& dp, vector<vector<int>>& s, int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = algo_dp_helper(d, dp, s, i, k) + algo_dp_helper(d, dp, s, k + 1, j) + d[i - 1] * d[k] * d[j];
        if (cost < dp[i][j]) {
            dp[i][j] = cost;
            s[i][j] = k; // Store the split point for optimal placement
        }
    }
    return dp[i][j];
}

void printOptimalParentheses(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParentheses(s, i, s[i][j]);
        cout << "*";
        printOptimalParentheses(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int algo_dp(vector<int>& d) {
    int n = d.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> s(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    int ans = algo_dp_helper(d, dp, s, 1, n - 1);
    cout << "Minimum number of multiplications required: " << ans << endl;
    cout << "Optimal Parentheses Placement: ";
    printOptimalParentheses(s, 1, n - 1);
    cout << endl;
    return ans;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int r, c;
        cout << "Enter row and column of matrix " << i + 1 << ": ";
        cin >> r >> c;
        if (i == 0) {
            d.push_back(r);
            d.push_back(c);
        } else {
            d.push_back(c);
        }
    }
    int ans = algo_dp(d);
    return 0;
}
