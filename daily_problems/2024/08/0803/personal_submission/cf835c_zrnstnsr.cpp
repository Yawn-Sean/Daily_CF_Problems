#include <bits/stdc++.h>
using namespace std;

int pre[11][102][102];

void solve() {
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i) {
        int x, y, b;
        cin >> x >> y >> b;
        pre[b][x+1][y+1]++;
    }
    for (int i = 1; i <= 101; ++i) for (int j = 1; j <= 101; ++j) for (int k = 0; k <= c; ++k)
        pre[k][i][j] += pre[k][i-1][j] + pre[k][i][j-1] - pre[k][i-1][j-1];
    while (q--) {
        int t, x1, x2, y1, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int k = 0; k <= c; ++k) {
            ans += (pre[k][x2+1][y2+1] - pre[k][x2+1][y1] - pre[k][x1][y2+1] + pre[k][x1][y1]) * ((k + t) % (c + 1));
        }
        cout << ans << endl;
    }
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
