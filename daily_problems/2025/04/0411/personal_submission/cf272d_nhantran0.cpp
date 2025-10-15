/**
 * https://codeforces.com/problemset/problem/272/D
 * D. Dima and Two Sequences
 * Solver: nhant
 * 2025-04-12 01:18:35
 * Submission: https://codeforces.com/problemset/submission/272/315041685
 */
#include <bits/stdc++.h>

using namespace std;

int m;

int mul(int a, int b) {
    return (int) ((int64_t) a * b % m);
}

int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[n + i][0];
        a[n + i][1] = i + 1;
    }
    sort(a.begin(), a.end(), [&](auto& u, auto& v) { return u[0] != v[0] ? u[0] < v[0] : u[1] < v[1]; });
    cin >> m;
    int res = 1, pow2 = 0;
    for (int i = 1, n2 = n * 2, k = 1; i < n2; i++) {
        if (a[i][0] == a[i - 1][0]) {
            int v = ++k;
            while (v % 2 == 0) {
                pow2++;
                v /= 2;
            }
            res = mul(res, v);
            if (a[i][1] == a[i - 1][1]) {
                pow2--;
            }
        } else {
            k = 1;
        }
    }
    res = mul(res, pow(2, pow2));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
