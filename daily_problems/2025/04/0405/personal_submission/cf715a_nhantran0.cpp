/**
 * https://codeforces.com/problemset/problem/715/A
 * A. Plus and Square Root
 * Solver: nhant
 * 2025-04-05 22:49:55
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << 2 << '\n';
    for (int i = 2; i <= n; i++) {
        cout << (((int64_t) i + 1) * (i + 1) * i - (i - 1)) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
