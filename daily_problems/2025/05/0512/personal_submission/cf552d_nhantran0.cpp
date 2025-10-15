/*
 https://codeforces.com/problemset/problem/552/D
 D. Vanya and Triangles
 Solver: nhant
 2025-05-12 19:11:41
 https://codeforces.com/problemset/submission/552/319418687
*/
#include <bits/stdc++.h>

using namespace std;

int mgcd[201][201];

void line_of(int x1, int y1, int x2, int y2, int& a, int& b, int& c) {
    if (x1 == x2) {
        a = 1;
        b = 0;
        c = -x1;
    } else if (y1 == y2) {
        a = 0;
        b = 1;
        c = -y1;
    } else {
        int g = mgcd[abs(y1 - y2)][abs(x2 - x1)];
        // important to have b positive
        if (x2 < x1) {
            g = -g;
        }
        a = (y1 - y2) / g;
        b = (x2 - x1) / g;
        c = -a * x1 - b * y1;
    }
}

int64_t hash_of(int a, int b, int c) {
    return ((int64_t)(a + 100) * 202 + b + 100) * 80002 + (c + 40000);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int X_MAX = 200;
    for (int i = 0; i <= X_MAX; i++) {
        mgcd[i][i] = mgcd[i][0] = mgcd[0][i] = i;
        for (int j = i + 1; j <= X_MAX; j++) {
            mgcd[i][j] = mgcd[j][i] = (i == 0 ? j : mgcd[i][j % i]);
        }
    }
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int64_t res = (int64_t)n * (n - 1) * (n - 2) / 6;
    if (n >= 3) {
        int m = n * (n - 1) / 2;
        vector<int64_t> linehash(m);
        int hi = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int a, b, c;
                line_of(x[i], y[i], x[j], y[j], a, b, c);
                linehash[hi++] = hash_of(a, b, c);
            }
        }
        sort(linehash.begin(), linehash.end());
        vector<int> segcnt;
        int cnt = 1;
        for (int i = 1; i < m; i++) {
            if (linehash[i - 1] != linehash[i]) {
                segcnt.push_back(cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        segcnt.push_back(cnt);
        vector<int> stp(m + 1);
        for (int v = 0; v <= n; v++) {
            stp[v * (v - 1) / 2] = v;
        }
        for (int c : segcnt) {
            int v = stp[c];
            res -= (int64_t)v * (v - 1) * (v - 2) / 6;
        }
    }
    cout << res << '\n';
}
