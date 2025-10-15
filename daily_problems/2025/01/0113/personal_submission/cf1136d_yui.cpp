#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    int cnt = 1; // 一定得在前面
    vector<int> to_swap(n);
    to_swap[p.back()] = 1;

    for (int i = n - 2; i >= 0; i--) {
        int r = 0;
        for (int y : g[p[i]]) {
            if (to_swap[y]) r++;
        }
        if (r == cnt) {
            // 可以和后面所有人换
            continue;
        } else {
            to_swap[p[i]] = 1;
            cnt++;
        }
    }

    println("{}", n - cnt);
}
