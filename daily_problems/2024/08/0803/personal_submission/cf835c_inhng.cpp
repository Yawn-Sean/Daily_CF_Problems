#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

void solve() {
    int n, q, c;
    cin >> n >> q >> c;
    int g[11][101][101];
    memset(g, 0, sizeof(g));
    while (n--) {
        int x, y, s;
        cin >> x >> y >> s;
        ++g[s][x][y];
    }
    for (int k = 0; k <= c; ++k) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                g[k][i][j] += g[k][i - 1][j] + g[k][i][j - 1] - g[k][i - 1][j - 1];
            }
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2, ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        for (int i = 0; i <= c; ++i) {
            ans += (g[i][x2][y2] - g[i][x1 - 1][y2] - g[i][x2][y1 - 1] + g[i][x1 - 1][y1 - 1]) * ((i + t) % (c + 1));
        }
        cout << ans << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
