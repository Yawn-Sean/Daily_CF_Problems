/**
 * https://codeforces.com/problemset/problem/509/C
 * C. Sums of Digits
 * Solver: nhant
 * 2025-04-16 20:41:09
 * https://codeforces.com/problemset/submission/509/315834562
 */
#include <bits/stdc++.h>

using namespace std;

array<int, 400> x;

void next(int xb, int b) {
    for (int i = 0, n = x.size(); i < n; i++) {
        if (xb < b && x[i] < 9 && b - xb <= 9 - x[i] + 9 * i) {
            b -= xb;
            int d = max(1, b - 9 * i);
            x[i] += d;
            b -= d;
            for (int j = 0; b > 0; j++) {
                int d = min(b, 9);
                x[j] = d;
                b -= d;
            }
            break;
        } else {
            xb -= x[i];
            x[i] = 0;
        }
    }
}

void solve() {
    fill(x.begin(), x.end(), 0);
    int n;
    cin >> n;
    for (int i = 0, prev = 0; i < n; i++) {
        int b;
        cin >> b;
        next(prev, b);
        stringstream s;
        for (int j = x.size() - 1, len = 0; j >= 0; j--) {
            if ((len == 0 && x[j] > 0) || len > 0) {
                s << (char) ('0' + x[j]);
                len++;
            }
        }
        prev = b;
        cout << s.str() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
