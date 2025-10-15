#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto& i : s) {
        cin >> i;
    }
    vector<int> col[n][10], row[n][10];
    int mincol[10], minrow[10], maxcol[10], maxrow[10];
    for (int i = 0; i < 10; i++)
        mincol[i] = minrow[i] = 1e9, maxcol[i] = maxrow[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t = s[i][j] - '0';
            col[j][t].push_back(i);
            row[i][t].push_back(j);
            mincol[t] = min(mincol[t], j);
            minrow[t] = min(minrow[t], i);
            maxcol[t] = max(maxcol[t], j);
            maxrow[t] = max(maxrow[t], i);
        }
    }
    for (int i = 0; i < 10; i++) {
        int res = 0;
        for (int j = 0; j < n; j++) {
            if (col[j][i].size()) {
                int len = max({col[j][i][0], col[j][i].back(),
                               n - 1 - col[j][i][0], n - 1 - col[j][i].back()});
                res = max({res, len * max(maxcol[i] - j, j - mincol[i])});
                len = col[j][i].back() - col[j][i][0];
                res = max(res, len * max(j, n - 1 - j));
            }
            if (row[j][i].size()) {
                int len = max({row[j][i][0], row[j][i].back(),
                               n - 1 - row[j][i][0], n - 1 - row[j][i].back()});
                res = max({res, len * max(maxrow[i] - j, j - minrow[i])});
                len = row[j][i].back() - row[j][i][0];
                res = max(res, len * max(j, n - 1 - j));
            }
        }
        cout << res << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}