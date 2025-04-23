/**
 * https://codeforces.com/problemset/problem/1092/C
 * C. Prefixes and Suffixes
 * Solver: nhant
 * 2025-04-23 18:30:26
 * https://codeforces.com/problemset/submission/1092/316799865
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n - 2;
    string s[m];
    vector<vector<int>> l2i(n, vector<int>(2));
    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        l2i[s[i].size()][cnt[s[i].size()]++] = i;
    }
    string res(m, '.');
    if (n == 2) {
        res[0] = 'P';
        res[1] = 'S';
    } else {
        string& u = s[l2i[n - 1][0]], v = s[l2i[n - 1][1]];
        bool ma = u.ends_with(v.substr(0, v.size() - 1));
        int maPreCnt = u.starts_with(s[l2i[n - 2][0]]) + u.starts_with(s[l2i[n - 2][1]]);
        int maSufCnt = v.ends_with(s[l2i[n - 2][0]]) + v.ends_with(s[l2i[n - 2][1]]);
        string t;
        if (ma && maPreCnt >= 1 && maSufCnt >= 1) {
            t = u + v[n - 2];
        } else {
            t = v + u[n - 2];
        }
        for (int i = 0; i < m; i++) {
            if (t.starts_with(s[i]) && cnt[(int)s[i].size()] >= 0) {
                res[i] = 'P';
                cnt[(int)s[i].size()] = -cnt[(int)s[i].size()];
            } else {
                res[i] = 'S';
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
