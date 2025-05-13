/*
 https://codeforces.com/problemset/problem/768/C
 C. Jon Snow and his Favourite Number
 Solver: nhant
 2025-05-12 15:15:38
 https://codeforces.com/problemset/submission/768/319343095, O(N + K * MAX_A)
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    int MAX_A = 1024;
    vector<int> f(MAX_A), g(MAX_A);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[a]++;
        g[a]++;
    }
    while (k--) {
        int cnt = 0;
        for (int i = 0; i < MAX_A; i++) {
            if (f[i] > 0) {
                int d = (cnt % 2 == 0) ? ((f[i] + 1) / 2) : (f[i] / 2);
                g[i] -= d;
                g[i ^ x] += d;
                cnt += f[i];
            }
        }
        copy(g.begin(), g.end(), f.begin());
    }
    int mn = MAX_A, mx = -1;
    for (int i = 0; i < MAX_A; i++) {
        if (f[i] > 0) {
            if (mn == MAX_A) mn = i;
            mx = i;
        }
    }
    cout << mx << " " << mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
