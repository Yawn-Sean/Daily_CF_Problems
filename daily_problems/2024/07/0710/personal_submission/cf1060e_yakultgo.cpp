#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt[2]{};
    vector<int> dep(n + 1);
    vector<int> sz(n + 1);
    ll ans = 0;
    function<void(int, int)> dfs = [&](int x, int fa) -> void {
        sz[x] = 1;
        dep[x] = dep[fa] + 1;
        for (int y : g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            ans += 1ll * sz[y] * (n - sz[y]);
            sz[x] += sz[y];
        }
        cnt[dep[x] & 1]++;
    };
    dfs(1, 0);
    cout << (ans + 1ll * cnt[0] * cnt[1]) / 2 << endl;
    return 0;
}