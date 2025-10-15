/*
 https://codeforces.com/problemset/problem/12/E
 E. Start of the season
 Solver: nhant
 2025-05-10 13:21:08
 https://codeforces.com/problemset/submission/12/319013793, 156 ms
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    vector<int> row_sum(n);
    for (int r = 0; r < n; r++) {
        for (int c = r + 1; c < n - 1; c++) {
            int x = (r + c) % (n - 1);
            g[r][c] = g[c][r] = x;
            row_sum[r] += x;
            row_sum[c] += x;
        }
        g[r][n - 1 - r] = n - 1;
        row_sum[r] += n - 1;
    }
    int m = (n - 1) * n / 2;
    for (int r = 1; r < n - 1; r++) {
        g[r][n - 1] = g[n - 1][r] = m - row_sum[r];
    }
    for (int r = 0; r < n; r++) {
        stringstream s;
        for (int c = 0; c < n; c++) {
            s << g[r][c] << " ";
        }
        cout << s.str() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
