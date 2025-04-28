/**
 * https://codeforces.com/problemset/problem/593/C
 * C. Beautiful Function
 * Solver: nhant
 * 2025-04-27 03:53:22
 * https://codeforces.com/problemset/submission/593/317385184, 46 ms, 100 KB
 * O(N)
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string rx, ry;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        string nx = format("({}*((1-abs((t-{})))+abs((1-abs((t-{}))))))", x/2, i, i);
        string ny = format("({}*((1-abs((t-{})))+abs((1-abs((t-{}))))))", y/2, i, i);
        if (i == 0) {
            rx = nx;
            ry = ny;
        } else {
            rx = format("({}+{})", rx, nx);
            ry = format("({}+{})", ry, ny);
        }
    }
    cout << rx << '\n' << ry << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
