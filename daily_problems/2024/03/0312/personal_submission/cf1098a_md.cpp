#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<int> parent(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> parent[i];
        parent[i]--;
        tree[parent[i]].push_back(i);
    }

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] == -1) {
            s[i] = inf;
        }
    }

    auto dfs = [&](auto self, int u) -> void {
        s[parent[u]] = min(s[parent[u]], s[u]);
        for (auto next : tree[u]) {
            self(self, next);
        }
    };

    dfs(dfs, 0);

    long long ret = s[0];
    auto dfs2 = [&](auto self, int u) -> void {
        if (s[u] < s[parent[u]]) {
            cout << -1 << endl;
            exit(0);
        }

        if (s[u] != inf) {
            ret += s[u] - s[parent[u]];
        }

        for (auto next : tree[u]) {
            self(self, next);
        }
    };

    dfs2(dfs2, 0);
    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}