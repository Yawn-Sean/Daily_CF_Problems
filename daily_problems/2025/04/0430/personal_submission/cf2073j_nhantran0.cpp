/*
 https://codeforces.com/contest/2073/problem/J
 J. Gathering Sharks
 Solver: nhant
 2025-05-01 04:21:39
 https://codeforces.com/contest/2073/submission/317883451, 93 ms, 100 KB
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        x[a] = i;
    }
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    for (int j = 2; j <= n; j++) {
        for (int i = j - 1; i >= 1; i--) {
            d[j][i] = d[j - 1][i] + abs(x[j] - x[i]);
            for (int k = j - 1; k > i; k--) {
                d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
            }
        }
    }
    cout << d[n][1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
