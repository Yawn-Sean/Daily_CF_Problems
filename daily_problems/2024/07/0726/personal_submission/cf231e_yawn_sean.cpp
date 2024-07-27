#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

struct unionfind {
  public:
    unionfind() : _n(0) {}
    explicit unionfind(int n) : _n(n), parent_or_size(n, -1) {}

    bool merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, mod = 1e9 + 7;
    cin >> n >> m;

    vector<vector<int>> tree(n);
    unionfind uf(n);

    vector<int> pow2(n + 1, 1);
    for (int i = 0; i < n; i ++) {
        pow2[i+1] = pow2[i] + pow2[i];
        if (pow2[i+1] >= mod) pow2[i+1] -= mod;
    }

    vector<pair<int, int>> edges;

    while (m --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        if (uf.leader(u) == uf.leader(v))
            edges.push_back({u, v});
        else {
            uf.merge(u, v);
            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
        }
    }

    vector<int> parent(n, -1), depth(n, 0), stk = {0}, order;

    while (stk.size()) {
        int u = stk.back();
        order.emplace_back(u);
        stk.pop_back();
        for (auto &v: tree[u])
            if (parent[u] != v) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                stk.push_back(v);
            }
    }

    vector<int> notes(n), col(n);
    iota(col.begin(), col.end(), 0);

    for (auto [u, v]: edges) {
        if (depth[u] < depth[v])
            swap(u, v);
        
        int cu = u, cv = v;
        while (depth[cu] > depth[cv])
            cu = parent[cu];
        
        while (cu != cv)
            cu = parent[cu], cv = parent[cv];
        
        int nu, nv;
        while (u != cu)
            nu = parent[u], col[u] = cu, u = nu;
        
        while (v != cv)
            nv = parent[v], col[v] = nv, v = nv;
        
        notes[cu] = 1;
    }
    
    vector<int> size(n, 1), heads(n);
    iota(heads.begin(), heads.end(), 0);

    for (auto x = order.rbegin(); x != order.rend(); x ++) {
        int u = *x;
        if (parent[u] >= 0)
            size[parent[u]] += size[u];
    }

    for (auto &u: order) {
        int chosen = -1;
        for (auto &v: tree[u])
            if (parent[v] == u) {
                notes[v] += notes[u];
                if (chosen == -1 or size[v] > size[chosen])
                    chosen = v;
            }
        if (chosen != -1) heads[chosen] = heads[u];
    }

    int q;
    cin >> q;
    
    while (q --) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        u = col[u];
        v = col[v];
        int ans = notes[u] + notes[v];
        while (heads[u] != heads[v]) {
            if (depth[heads[u]] > depth[heads[v]]) u = parent[heads[u]];
            else v = parent[heads[v]];
        }
        int l = col[(depth[u] < depth[v] ? u : v)];
        ans -= notes[l];
        if (parent[l] >= 0) ans -= notes[parent[l]];
        cout << pow2[ans] << '\n';
    }

    return 0;
}