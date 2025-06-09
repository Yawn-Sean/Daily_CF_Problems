/**
 * https://codeforces.com/contest/1938/problem/C
 * C. Bit Counting Sequence
 * Solver: nhant
 * 2025-04-08 02:58:31
 * Submission: https://codeforces.com/contest/1938/submission/314416140
 */
#include <bits/stdc++.h>

using namespace std;

int64_t calc(vector<int> a, int n) {
    int done = 0;
    int64_t x = 0;
    if (n > 1) {
        for (int i = 1; i < n; i++) {
            int d = a[i] - a[i - 1];
            if (d > 1 || a[i] == 0) return -1;
            int64_t expPrev = (1LL << (1 - d)) - 1;
            int newDone = 1 - d + 1;
            int64_t mask = (1LL << min(done, newDone)) - 1;
            if ((x & mask) != (expPrev & mask)) {
                return -1;
            }
            done = max(done, newDone);
            x |= expPrev;
            x++;
        }
    }
    for (int i = 0, m = a[n - 1] - __builtin_popcountll(x); i < m; i++) {
        x |= (1LL << (done + i));
    }
    return x - n + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cout << calc(a, n) << '\n';
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
