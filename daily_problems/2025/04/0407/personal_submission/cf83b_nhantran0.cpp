/**
 * https://codeforces.com/problemset/problem/83/B
 * B. Doctor
 * Solver: nhant
 * 2025-04-07 19:09:57
 * Submission: https://codeforces.com/problemset/submission/83/314351031
 */
#include <bits/stdc++.h>

using namespace std;

// f() returns whether total served customers <= k
bool f(int rnd, int64_t k, vector<int>& a) {
    for (int x : a) {
        k -= min(rnd, x);
        if (k < 0) return false;
    }
    return true;
}

void solve() {
    int n;
    int64_t k;
    cin >> n >> k;
    vector<int> a(n);
    int64_t total = 0;
    int mx = 0;
    for (int& x : a) {
        cin >> x;
        total += x;
        mx = max(mx, x);
    }
    if (total < k) cout << "-1\n";
    else if (total == k) cout << "\n";
    else {
        // find largest i where f(i, k, a) = true
        int lo = 0, hi = mx;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (f(mi, k, a)) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        for (int& x : a) {
            int d = min(x, lo);
            x -= d;
            k -= d;
        }
        int start = 0;
        for (; start < n && k > 0; start++) {
            if (a[start] > 0) {
                a[start]--;
                k--;
            }
        }
        for (int i = 0; i < n; i++) {
            int j = start + i >= n ? start + i - n : start + i;
            if (a[j] > 0) {
                cout << (j + 1) << " ";
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
