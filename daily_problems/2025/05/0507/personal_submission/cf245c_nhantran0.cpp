/*
 https://codeforces.com/problemset/problem/245/C
 C. Game with Coins
 Solver: nhant
 2025-05-07 23:52:24
 https://codeforces.com/problemset/submission/245/318750650
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = (n - 1) / 2; i > 0; i--) {
        int d = max(a[i * 2], a[i * 2 + 1]);
        if (i == 1) {
            d = max(d, a[i]);
        }
        res += d;
        a[i] = max(0, a[i] - d);
        a[i * 2] = a[i * 2 + 1] = 0;
    }
    if ((n == 1 && a[1] > 0) || (n == 2 && (a[1] > 0 || a[2] > 0)) || (n % 2 == 0 && a[n] > 0)) {
        res = -1;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
