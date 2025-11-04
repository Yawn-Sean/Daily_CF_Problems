#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;

    DSU(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b) { return find(a) == find(b); }

    void reset() {
        iota(parent.begin(), parent.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<pair<int, int>> edges(m);
    for (auto &[u, v]: edges) {
        cin >> u >> v;
        --u; --v;
        if (nums[u] > nums[v]) swap(u, v);
    }

    sort(edges.begin(), edges.end(), [&](auto &x, auto &y) {
        return nums[x.second] < nums[y.second];
    });

    DSU uf(n);
    int ans = 1e9;

    for (int i = 0; i < n; i++) {
        uf.reset();
        for (auto &[u, v]: edges) {
            if (nums[u] >= nums[i]) {
                uf.merge(u, v);
                if (uf.same(0, 1)) {
                    ans = min(ans, nums[v] - nums[i]);
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
