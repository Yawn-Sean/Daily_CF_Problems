/**
 * https://codeforces.com/problemset/problem/336/B
 * B. Vasily the Bear and Fly
 * Solver: nhant
 * 2025-04-02 02:51:52
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, R;
    cin >> m >> R;
    double res = 2 * R * (m + (2 + sqrt(2)) * (m - 1) + (m - 1LL) * (m - 2) * (sqrt(2) + m / 3.0)) / m / m;
    cout << fixed << setprecision(10) << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
