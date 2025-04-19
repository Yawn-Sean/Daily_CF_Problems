/**
 * https://codeforces.com/problemset/problem/317/A
 * A. Perfect Pair
 * Solver: nhant
 * 2025-04-19 16:55:58
 * https://codeforces.com/problemset/submission/317/316198304
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t x, y, m;
    cin >> x >> y >> m;
    int64_t res = 0;
    if (max(x, y) < m) {
        if (x <= 0 && y <= 0) {
            res = -1;
        } else {
            if (x > y) {
                swap(x, y);
            }
            if (x <= 0) {
                res = (-x + y - 1) / y;
                x += res * y;
            }
            while (x < m && y < m) {
                if (x <= y) {
                    x += y;
                } else {
                    y += x;
                }
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
