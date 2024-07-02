#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

vector<int> mp[200200];
vector<int> ans;
map<pair<int, int>, int> edge;
void init(int n) {
    for (int i = 1; i <= n; i++) {
        mp[i].clear();
    }
    edge.clear();
    ans.clear();
}

int dfs(int u, int fa) {
    int cnt = 1;
    for (auto v : mp[u]) {
        if (v == fa)
            continue;
        cnt += dfs(v, u);
    }
    if (cnt == 3) {
        ans.push_back(edge[make_pair(u,fa)]);
        cnt = 0;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
        edge[{u, v}] = i;
        edge[{v, u}] = i;
    }
    if (n % 3) {
        cout << -1 << endl;
        return;
    } else {
        dfs(1, 0);
        if ((int)ans.size() * 3 != n) {
            cout << -1 << endl;
        } else {
            cout << n / 3 - 1 << endl;
            for (int i = 0; i < (int)ans.size() - 1; i++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
}

signed main() {
    IOS int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
