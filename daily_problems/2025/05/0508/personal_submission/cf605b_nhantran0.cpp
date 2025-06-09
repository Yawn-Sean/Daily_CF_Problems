/*
 https://codeforces.com/problemset/problem/605/B
 B. Lazy Student
 Solver: nhant
 2025-05-08 22:11:22
 https://codeforces.com/problemset/submission/605/318849923
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), mn(n + 1), ord(m);
    vector<vector<int>> e(2, vector<int>(m));
    fill(mn.begin(), mn.end(), (int)1e9 + 10);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] == b[j] ? a[i] < a[j] : b[i] > b[j]; });
    mn[1] = e[0][0];
    for (int i = 0, u = 1, v = 2; i < n - 1; i++) {
        e[0][ord[i]] = u;
        e[1][ord[i]] = v;
        mn[v] = a[ord[i]];
        v++;
    }
    for (int i = n - 1, u = 2, v = 3; i < m; i++) {
        e[0][ord[i]] = u;
        e[1][ord[i]] = v;
        if (mn[v] > a[ord[i]]) {
            cout << "-1\n";
            return;
        }
        u++;
        if (u == v) {
            u = 2;
            v++;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << e[0][i] << " " << e[1][i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
