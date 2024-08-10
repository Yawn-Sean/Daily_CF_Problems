#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> u, v;
    vector<vector<int>> e(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        u.push_back(x);
        v.push_back(y);
        e[x].push_back(i);
        e[y].push_back(i);
    }

    vector<int> sz(n, 1), ans;

    function<void(int, int)> dfs = [&] (int x, int f) {
        for (auto &i: e[x]) {
            if (i == f) continue;
            int y = u[i] ^ v[i] ^ x;
            dfs(y, i);
            if (sz[y] == 0) ans.push_back(i + 1);
            sz[x] += sz[y];
        }
        if (sz[x] == 3) sz[x] = 0;
    };

    dfs(0, -1);
    if (((int)ans.size() + 1) * 3 == n) {
        cout << ans.size() << '\n';
        for (auto &x: ans) 
            cout << x << ' ';
        cout << '\n';
    }
    else 
        cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}