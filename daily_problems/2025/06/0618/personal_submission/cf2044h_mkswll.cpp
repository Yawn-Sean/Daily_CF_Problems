#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _;
    cin >> _;
    while(_--) {
        int n, m;
        cin >> n >> m;
        vector a(n + 1, vector<int> (n + 1));
        vector pre(n + 1, vector<ll> (n + 1)), rpre(pre), ppre(pre);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                pre[i][j] = (ll) a[i][j] * ((i - 1) * n + j) + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
                rpre[i][j] = (ll) a[i][j] * i + rpre[i - 1][j] + rpre[i][j - 1] - rpre[i - 1][j - 1];
                ppre[i][j] = a[i][j] + ppre[i - 1][j] + ppre[i][j - 1] - ppre[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= m; ++i) {
            int lx, ly, rx, ry;
            cin >> lx >> ly >> rx >> ry;
            --lx;
            --ly;
            int len = ry - ly;
            ll ans = pre[rx][ry] - pre[lx][ry] - pre[rx][ly] + pre[lx][ly];
            ans -= (rpre[rx][ry] - rpre[lx][ry] - rpre[rx][ly] + rpre[lx][ly]) * (n - len);
            ans += (ppre[rx][ry] - ppre[lx][ry] - ppre[rx][ly] + ppre[lx][ly]) * (1 - (lx * n + ly + 1 - (ll) (n - len) * (lx + 1)));
            cout << ans << " \n"[i == m];
        }
    }
}
