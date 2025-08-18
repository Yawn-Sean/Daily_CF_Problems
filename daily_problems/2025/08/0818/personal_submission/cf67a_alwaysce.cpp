#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n;
    cin >> n;

    DSU dsu(n);
    string s;
    cin >> s;

    vector<vector<int>> path(n);
    for (int i = 0; i < n - 1; i++) {
        char c = s[i];
        if (c == '=') {
            dsu.merge(i, i + 1);
        }
    }

    if (dsu.size(0) == n) {
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        char c = s[i];
        int x = dsu.find(i), y = dsu.find(i + 1);
        if (c == 'R') {
            path[x].push_back(y);
        } else if (c == 'L') {
            path[y].push_back(x);
        }
    }

    vector<int> ans(n, 0);
    auto topo = [&]() {
        vector<int> in_degree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto& j: path[i]) {
                ++in_degree[j];
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (path[i].size() > 0 && in_degree[i] == 0) {
                q.push(i);
            }
        }

        int cur = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                ans[u] = cur;
                q.pop();
                for (auto& v: path[u]) {
                    if (--in_degree[v] == 0) {
                        q.push(v);
                    }
                }
            }
            cur++;
        }
    };

    topo();
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = ans[dsu.find(i)];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
