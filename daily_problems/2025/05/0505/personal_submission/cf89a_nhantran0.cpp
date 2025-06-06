/*
 https://codeforces.com/problemset/problem/89/A
 A. Robbery
 Solver: nhant
 2025-05-06 08:04:38
 https://codeforces.com/problemset/submission/89/318566211
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int minOdd = (int)1e5;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 1) {
            minOdd = min(minOdd, x);
        }
    }
    int64_t res = 0;
    if (n % 2 == 1) {
        if (n == 1) {
            res = min<int64_t>((int64_t) m * k, minOdd);
        } else {
            res = min<int64_t>((int64_t) m / ((n + 1) / 2) * k, minOdd);
        }
    }
    cout << res << '\n';
}
