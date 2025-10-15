/**
 * https://codeforces.com/problemset/problem/234/H
 * H. Merging Two Decks
 * Solver: nhant
 * 2025-04-25 02:04:44
 * https://codeforces.com/problemset/submission/234/317091977
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n;
    int alast1 = 0, blast1 = n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] == 1 ? i + 1 : -(i + 1);
        if (a[i] > 0) alast1 = a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i] = b[i] == 1 ? n + i + 1 : -(n + i + 1);
        if (b[i] > 0) blast1 = b[i];
    }
    vector<int> c(n + m);
    int i = 0;
    for (; i < n - alast1; i++) {
        c[n + m - i - 1] = a[n - 1 - i];
    }
    for (int j = 0; j < m + n - blast1; i++, j++) {
        c[n + m - i - 1] = b[m - 1 - j];
    }
    int len0 = i, ai = alast1 - 1, bi = blast1 - n - 1;
    bool pos = true;
    while (i < n + m) {
        while (ai >= 0 && ((pos && a[ai] > 0) || (!pos && a[ai] < 0))) {
            c[n + m - i - 1] = a[ai--];
            i++;
        }
        while (bi >= 0 && ((pos && b[bi] > 0) || (!pos && b[bi] < 0))) {
            c[n + m - i - 1] = b[bi--];
            i++;
        }
        pos = !pos;
    }
    for (int x : c) cout << abs(x) << " ";
    cout << '\n';
    vector<int> ops;
    for (int i = 1; i < n + m - len0; i++) {
        if ((c[i - 1] < 0 && c[i] > 0) || (c[i - 1] > 0 && c[i] < 0)) ops.push_back(i);
    }
    if (len0 < n + m) ops.push_back(n + m - len0);
    cout << ops.size() << '\n';
    for (int x : ops) cout << x << " ";
    if (ops.size() > 0) cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
}
