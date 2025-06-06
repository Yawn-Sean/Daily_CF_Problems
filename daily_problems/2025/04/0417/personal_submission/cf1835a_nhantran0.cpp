/**
 * https://codeforces.com/problemset/problem/1835/A
 * A. k-th equality
 * Solver: nhant
 * 2025-04-17 23:50:28
 * https://codeforces.com/problemset/submission/1835/315986320
 */
#include <bits/stdc++.h>

using namespace std;

int minWith(int d) {
    int r = 1;
    while (d > 1) {
        d--;
        r *= 10;
    }
    return r;
}

int maxWith(int d) {
    int r = 1;
    while (d > 0) {
        d--;
        r *= 10;
    }
    return r - 1;
}

void solve() {
    int A, B, C;
    int64_t k;
    cin >> A >> B >> C >> k;
    int aMin = minWith(A), aMax = maxWith(A);
    int bMin = minWith(B), bMax = maxWith(B);
    int cMin = minWith(C), cMax = maxWith(C);
    bool solved = false;
    for (int a = aMin; a <= aMax; a++) {
        int cl = max(cMin, a + bMin), cr = min(cMax, a + bMax);
        if (cl <= cr) {
            int64_t d = min<int64_t>(k, cr - cl + 1);
            k -= d;
            if (k == 0) {
                int c = cl - 1 + (int) d;
                cout << a << " + " << c - a << " = " << c << '\n';
                solved = true;
                break;
            }
        }
    }
    if (!solved) cout << "-1\n";
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
