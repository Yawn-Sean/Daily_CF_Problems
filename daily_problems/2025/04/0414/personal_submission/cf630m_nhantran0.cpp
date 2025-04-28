/**
 * https://codeforces.com/problemset/problem/630/M
 * M. Turn
 * Solver: nhant
 * 2025-04-14 22:13:13
 * https://codeforces.com/problemset/submission/630/315583464
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t x;
    cin >> x;
    int A = 360;
    x %= A;
    if (x < 0) x += A;
    x = (x <= 45 || x >= 315 ? 0 : x);
    cout << (x + 44) / 90 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
