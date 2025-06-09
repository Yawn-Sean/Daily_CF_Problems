/**
 * https://codeforces.com/problemset/problem/380/A
 * A. Sereja and Prefixes
 * Solver: nhant
 * 2025-03-30 19:35:27
 */
#include <bits/stdc++.h>

using namespace std;

int find(int64_t p, int hi, vector<int64_t>& len, vector<vector<int>>& ops) {
    int lo = 0;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (p <= len[mi]) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    if (ops[hi][0] == 1) return ops[hi][1];
    p = (p - len[hi - 1] - 1) % ops[hi][1] + 1;
    return find(p, hi, len, ops);
}

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> ops(m, vector<int>(3));
    vector<int64_t> len(m);
    for (int i = 0; i < m; i++) {
        vector<int>& op = ops[i];
        cin >> op[0];
        if (op[0] == 1) {
            cin >> op[1];
            len[i] = (i > 0 ? len[i - 1] : 0) + 1;
        } else {
            cin >> op[1] >> op[2];
            len[i] = len[i - 1] + (int64_t) op[1] * op[2];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t p;
        cin >> p;
        cout << (i == 0 ? "" : " ") << find(p, (int) len.size(), len, ops);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
