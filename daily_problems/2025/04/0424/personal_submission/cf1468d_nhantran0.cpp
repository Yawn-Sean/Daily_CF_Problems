/**
 * https://codeforces.com/problemset/problem/1468/D
 * D. Firecrackers
 * Solver: nhant
 * 2025-04-24 23:41:46
 * https://codeforces.com/problemset/submission/1468/317045542
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> s(m);
    for (int& x : s) cin >> x;
    sort(s.begin(), s.end());
    int d = a < b ? a : n - a + 1;
    int res = 0;
    for (int i = m - 1, k = abs(a - b) - 1; i >= 0 && k > 0; i--) {
        if (s[i] < d + k) {
            res++;
            k--;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
