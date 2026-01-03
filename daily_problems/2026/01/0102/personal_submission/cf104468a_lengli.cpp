#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> parent, sz;

    UnionFind(int n) : n(n), parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> outs;
    outs.reserve(t);

    while (t--) {
        int n;
        cin >> n;

        vector<vector<pair<int,int>>> pos(2 * n + 1);

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pos[x].push_back({i, 0});
            pos[y].push_back({i, 1});
        }

        bool flg = true;
        UnionFind uf(2 * n);

        for (int i = 0; i <= 2 * n; i++) {
            if ((int)pos[i].size() > 2) {
                flg = false;
            }
            else if ((int)pos[i].size() == 2) {
                auto [idx1, f1] = pos[i][0];
                auto [idx2, f2] = pos[i][1];
                if (f1 != f2) {
                    uf.merge(idx1, idx2);
                    uf.merge(idx1 + n, idx2 + n);
                } else {
                    uf.merge(idx1 + n, idx2);
                    uf.merge(idx1, idx2 + n);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (uf.find(i) == uf.find(i + n)) {
                flg = false;
            }
        }

        if (!flg) {
            outs.push_back(-1);
        } else {
            vector<int> cnt(n, 0), cnt1(n, 0);

            for (int i = 0; i < 2 * n; i++) {
                int r = uf.find(i);
                if (r < n) {
                    cnt[r]++;
                    if (i < n) cnt1[r]++;
                }
            }

            long long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += min(cnt1[i], cnt[i] - cnt1[i]);
            }

            outs.push_back(ans);
        }
    }

    for (auto x : outs)
        cout << x << '\n';

    return 0;
}
