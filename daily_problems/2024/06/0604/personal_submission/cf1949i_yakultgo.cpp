#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector<int> g[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = a[i][0] - a[j][0];
            int y = a[i][1] - a[j][1];
            ll d = 1ll * x * x + 1ll * y * y;
            if (d == 1ll * (a[i][2] + a[j][2]) * (a[i][2] + a[j][2])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> cnt(2);
    vector<int> vis(n + 1, -1);
    function<bool(int, int)> dfs = [&](int x, int v) -> bool {
        vis[x] = v;
        cnt[v]++;
        bool ok = true;
        for (int y : g[x]) {
            if (vis[y] == -1) {
                if (!dfs(y, v ^ 1)) {
                    ok = false;
                }
            } else if (vis[y] == v) {
                ok = false;
            }
        }
        return ok;
    };
    for (int i = 1; i <= n; i++) {
        if (vis[i] != -1) continue;
        cnt[0] = cnt[1] = 0;
        bool ok = dfs(i, 0);
        if (ok && cnt[0] != cnt[1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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