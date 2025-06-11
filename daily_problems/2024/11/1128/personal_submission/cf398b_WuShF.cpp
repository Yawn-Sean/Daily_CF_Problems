#include <bits/stdc++.h>
#define IOS cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
const int N = 2e3 + 5;
int n, m;
double dp[N][N];
void solve() {
    cin >> n >> m;
    set<int> cs, rs;
    for (int i = 1; i <= m; i++) {
        int r, c;
        cin >> r >> c;
        rs.insert(r);
        cs.insert(c);
    }
    int v1 = n - rs.size(), v2 = n - cs.size();
    for (int i = v1; i >= 0; i--) {
        for (int j = v2; j >= 0; j--) {
            if (i == v1 && j == v2)
                continue;
            dp[i][j] =
                (1.0 * n * n + 1.0 * (v1 - i) * (v2 - j) * dp[i + 1][j + 1] +
                 1.0 * (v1 - i) * (n - v2 + j) * dp[i + 1][j] +
                 1.0 * (n - v1 + i) * (v2 - j) * dp[i][j + 1]) /
                (n * n - (n - v1 + i) * (n - v2 + j));
        }
    }
    cout << fixed << setprecision(4) << dp[0][0];
}

signed main() {
    IOS;
    solve();
    return 0;
}
