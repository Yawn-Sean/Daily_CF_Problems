/**
 * https://codeforces.com/problemset/problem/690/E1
 * E1. Photographs (I)
 * Solver: nhant
 * 2025-04-29 12:27:31
 * https://codeforces.com/problemset/submission/690/317693743, 1483 ms, 1500 KB
 */
#include <bits/stdc++.h>

using namespace std;

int a[601][601];

int diff(int r1, int r2, int w) {
    int d = 0;
    for (int i = 0; i < w; i++) {
        d += abs(a[r1][i] - a[r2][i]);
    }
    return d;
}

void solve() {
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    int topDiff = diff(0, h - 1, w), midDiff = diff(h / 2 - 1, h / 2, w);
    cout << (topDiff < midDiff ? "YES" : "NO") << '\n';
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
