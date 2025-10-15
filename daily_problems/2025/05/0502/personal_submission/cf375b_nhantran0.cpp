/*
 https://codeforces.com/contest/375/problem/B
 B. Maximum Submatrix 2
 Solver: nhant
 2025-05-02 15:23:47
 https://codeforces.com/contest/375/submission/318078307, 1140 ms, 94500 KB, slow
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    vector<vector<int>> end(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = m - 1; j >= 0; j--) {
            if (s[j] == '0') {
                end[i][j] = -1;
            } else {
                end[i][j] = j == m - 1 || s[j + 1] == '0' ? j : end[i][j + 1];
            }
        }
    }
    int res = 0;
    vector<int> dif(m + 1);
    for (int c = 0; c < m; c++) {
        fill(dif.begin(), dif.end(), 0);
        for (int r = 0; r < n; r++) {
            if (end[r][c] == -1) {
                dif[c]--;
            } else {
                dif[end[r][c] + 1]--;
            }
        }
        int h = n;
        for (int j = c; j <= m && h > 0; j++) {
            h += dif[j];
            res = max(res, h * (j - c + 1));
        }
    }
    cout << res << '\n';
}
