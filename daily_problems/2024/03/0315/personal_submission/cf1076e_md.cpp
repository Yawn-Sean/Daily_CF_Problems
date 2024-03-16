#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<vector<pair<int, int>>> ops(n);
    int q;
    cin >> q;
    while (q--) {
        int v, d, x;
        cin >> v >> d >> x;
        v--;

        ops[v].push_back({d, x});
    }

    vector<long long> val(n);
    vector<long long> diffs(n);
    auto dfs = [&](auto self, int cur, int parent, long long sum, int depth) -> void {
        sum += diffs[depth];
        for (auto[d, x] : ops[cur]) {
            sum += x;
            if (depth + d + 1 < n) {
                diffs[depth + d + 1] -= x; 
            }   
        }
        val[cur] = sum;

        for (auto next : tree[cur]) {
            if (next != parent) {
                self(self, next, cur, sum, depth + 1);
            }
        }

        for (auto[d, x] : ops[cur]) {
            if (depth + d + 1 < n) {
                diffs[depth + d + 1] += x; 
            }   
        }
    };

    dfs(dfs, 0, -1, 0ll, 0);

    for (int i = 0; i < n; ++i) {
        cout << val[i] << " \n"[i == n - 1];
    }
    return;
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