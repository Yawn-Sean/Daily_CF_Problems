#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<ll> row(n), col(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j]) {
                row[i] += a[i][j];
                col[j] += a[i][j];
            }
        }
    }
    if (n * m <= 4) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += row[i];
        }
        cout << ans << endl;
        return;
    }
    // 五种取法、四行、四列、一行三列、三行一列、两行两列
    vector<ll> trow = row, tcol = col;
    sort(trow.begin(), trow.end(), greater<ll>());
    sort(tcol.begin(), tcol.end(), greater<ll>());
    ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
    if (n >= 4) {
        ans1 = trow[0] + trow[1] + trow[2] + trow[3];
    }
    if (m >= 4) {
        ans2 = tcol[0] + tcol[1] + tcol[2] + tcol[3];
    }

    if (n >= 3 && m >= 1) {
        // 先固定一列，再取三行
        for (int j = 0; j < m; j++) {
            ll m1 = 0, m2 = 0, m3 = 0;
            for (int i = 0; i < n; i++) {
                if (row[i] - a[i][j] >= m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = row[i] - a[i][j];
                } else if (row[i] - a[i][j] >= m2) {
                    m3 = m2;
                    m2 = row[i] - a[i][j];
                } else if (row[i] - a[i][j] >= m3) {
                    m3 = row[i] - a[i][j];
                }
            }
            ans3 = max(ans3, col[j] + m1 + m2 + m3);
        }
    }
    if (n >= 1 && m >= 3) {
        // 先固定一行，再取三列
        for (int i = 0; i < n; i++) {
            ll m1 = 0, m2 = 0, m3 = 0;
            for (int j = 0; j < m; j++) {
                if (col[j] - a[i][j] >= m1) {
                    m3 = m2;
                    m2 = m1;
                    m1 = col[j] - a[i][j];
                } else if (col[j] - a[i][j] >= m2) {
                    m3 = m2;
                    m2 = col[j] - a[i][j];
                } else if (col[j] - a[i][j] >= m3) {
                    m3 = col[j] - a[i][j];
                }
            }
            ans4 = max(ans4, row[i] + m1 + m2 + m3);
        }
    }
    if (n >= 2 && m >= 2) {
        if (n <= m) {
            for (int i1 = 0; i1 < n; i1++) {
                for (int i2 = i1 + 1; i2 < n; i2++) {
                    ll m1 = 0, m2 = 0;
                    for (int j = 0; j < m; j++) {
                        if (col[j] - a[i1][j] - a[i2][j] >= m1) {
                            m2 = m1;
                            m1 = col[j] - a[i1][j] - a[i2][j];
                        } else if (col[j] - a[i1][j] - a[i2][j] >= m2) {
                            m2 = col[j] - a[i1][j] - a[i2][j];
                        }
                    }
                    ans5 = max(ans5, row[i1] + row[i2] + m1 + m2);
                }
            }
        } else {
            // 如果n>m则枚举列，否则枚举行
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = j1 + 1; j1 < m; j1++) {
                    ll m1 = 0, m2 = 0;
                    for (int i = 0; i < n; i++) {
                        if (row[i] - a[i][j1] - a[i][j2] >= m1) {
                            m2 = m1;
                            m1 = row[i] - a[i][j1] - a[i][j2];
                        } else if (row[i] - a[i][j1] - a[i][j2] >= m2) {
                            m2 = row[i] - a[i][j1] - a[i][j2];
                        }
                    }
                    ans5 = max(ans5, col[j1] + col[j2] + m1 + m2);
                }
            }
        }
    }
    cout << max({ans1, ans2, ans3, ans4, ans5}) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}