#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    map<pair<int, int>, int> indices;
    vector<int> w(n - 1);
    for (int i = 0, a, b, l; i < n - 1; i++) {
        cin >> a >> b >> l;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        w[i] = l;
        if (a > b) swap(a, b);
        indices[{a, b}] = i;
    }

    long long total = 0LL;
    vector<long long> t(n - 1);
    function<int(int, int)> dfs = [&] (int u, int p) {
        int tu = 1;
        for (auto& v : g[u]) if (v != p) {
            int tv = dfs(v, u);
            int i = 0;
            if (u > v) i = indices[{v, u}];
            else i = indices[{u, v}];
            t[i] = 1LL * tv * (n - tv);
            total += 2LL * w[i] * t[i];
            tu += tv;
        }
        return tu;
    };

    dfs(0, -1);

    int q;
    cin >> q;
    long long den = 1LL * n * (n - 1);
    for (int i = 0, j, l; i < q; i++) {
        cin >> j >> l;
        j--;
        total -= 2LL * t[j] * (w[j] - l);
        w[j] = l;
        cout << fixed << setprecision(10) << static_cast<double>(total) * 3 / den << "\n";
    }

    return 0;
}

