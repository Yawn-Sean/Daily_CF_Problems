/**
 * https://codeforces.com/problemset/problem/490/D
 * D. Chocolate
 * Solver: nhant
 * 2025-04-23 02:39:16
 * https://codeforces.com/problemset/submission/490/316729331
 */
#include <bits/stdc++.h>

using namespace std;

array<int,3> reduce(int v) {
    int c2 = 0, c3 = 0;
    while (v > 0 && v % 2 == 0) {
        v /= 2;
        c2++;
    }
    while (v > 0 && v % 3 == 0) {
        v /= 3;
        c3++;
    }
    return {v, c2, c3};
}

void restore(array<int,3>& v) {
    while (v[1] > 0) {
        v[0] *= 2;
        v[1]--;
    }
    while (v[2] > 0) {
        v[0] *= 3;
        v[2]--;
    }
}

void solve() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    array<int,3> x1 = reduce(a1), y1 = reduce(b1), x2 = reduce(a2), y2 = reduce(b2);
    if ((int64_t) x1[0] * y1[0] != (int64_t) x2[0] * y2[0]) {
        cout << "-1\n";
        return;
    }
    int cnt = 0;
    while (x1[2] + y1[2] > x2[2] + y2[2]) {
        if (x1[2] > 0) {
            x1[2]--;
            x1[1]++;
        } else {
            y1[2]--;
            y1[1]++;
        }
        cnt++;
    }
    while (x1[2] + y1[2] < x2[2] + y2[2]) {
        if (x2[2] > 0) {
            x2[2]--;
            x2[1]++;
        } else {
            y2[2]--;
            y2[1]++;
        }
        cnt++;
    }
    while (x1[1] + y1[1] > x2[1] + y2[1]) {
        if (x1[1] > 0) x1[1]--;
        else y1[1]--;
        cnt++;
    }
    while (x1[1] + y1[1] < x2[1] + y2[1]) {
        if (x2[1] > 0) x2[1]--;
        else y2[1]--;
        cnt++;
    }
    restore(x1);
    restore(y1);
    restore(x2);
    restore(y2);
    cout << cnt << "\n" << x1[0] << " " << y1[0] << "\n" << x2[0] << " " << y2[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
