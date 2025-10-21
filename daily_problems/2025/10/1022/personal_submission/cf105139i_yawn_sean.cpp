#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;


#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

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

    void init() {
        for (auto &x: parent_or_size) x = -1;
    }

    bool merge_to(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        parent_or_size[y] += parent_or_size[x];
        parent_or_size[x] = y;
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
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


template <class S, S (*op)(S, S)> struct ST {
	public:
		explicit ST(const std::vector<S>& v) : _n(int(v.size())) {
			int bit = 32 - __builtin_clz(_n);
			d = vector<vector<S>>(bit, vector<S>(_n, 0));
			for (int i = 0; i < _n; i ++)
				d[0][i] = v[i];
			for (int i = 0; i < bit - 1; i ++) {
				for (int j = 0; (j + (1 << i)) < _n; j ++) {
					d[i + 1][j] = op(d[i][j], d[i][j + (1 << i)]);
				}
			}
		}

		S prod(int l, int r) const {
			int bit = 31 - __builtin_clz(r - l);
			return op(d[bit][l], d[bit][r - (1 << bit)]);
		}

	private:
		int _n, size;
		std::vector<vector<S>> d;
};

long long op(long long x, long long y) {return min(x, y);}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<vector<int>> path(n);

		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<int> parent(n + 1, 0), depth(n + 1, 0), ls(n, 0);
		depth[n] = -1;

		vector<long long> dfs_order;

		auto dfs = [&] (auto &self, int u, int p) -> void {
			parent[u] = p;
			ls[u] = dfs_order.size();
			dfs_order.emplace_back(u);

			for (auto &v: path[u]) {
				if (v != p) {
					depth[v] = depth[u] + 1;
					self(self, v, u);
					dfs_order.emplace_back(u);
				}
			}
		};

		dfs(dfs, 0, n);

		for (auto &x: dfs_order)
			x += 1ll * depth[x] * n;

		ST<long long, op> st(dfs_order);

		auto lca = [&] (int u, int v) -> int {
			if (ls[u] > ls[v]) swap(u, v);
			return st.prod(ls[u], ls[v] + 1) % n;
		};

		auto dis = [&] (int u, int v) -> int {
			return depth[u] + depth[v] - depth[lca(u, v)] * 2;
		};

		vector<int> tmstamps(n, q), top(n + 1);
		atcoder::dsu uf(n + 1);

		iota(top.begin(), top.end(), 0);

		for (int tid = 0; tid < q; tid ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			auto l = lca(u, v);

			while (true) {
				u = top[uf.leader(u)];
				if (depth[u] < depth[l]) break;
				tmstamps[u] = tid;
				int ntop = top[uf.leader(parent[u])];
				uf.merge(u, parent[u]);
				top[uf.leader(u)] = ntop;
			}

			while (true) {
				v = top[uf.leader(v)];
				if (depth[v] < depth[l]) break;
				tmstamps[v] = tid;
				int ntop = top[uf.leader(parent[v])];
				uf.merge(v, parent[v]);
				top[uf.leader(v)] = ntop;
			}
		}

		vector<vector<int>> tmp(q + 1);
		for (int i = 0; i < n; i ++)
			tmp[tmstamps[i]].emplace_back(i);
		
		vector<int> ans(q, 0);

		vector<int> us(n + 1), vs(n + 1), ds(n + 1), col(n + 1, 0);
		int cur;
		
		iota(us.begin(), us.end(), 0);
		iota(vs.begin(), vs.end(), 0);
		fill(ds.begin(), ds.end(), 0);
		fill(col.begin(), col.end(), 0);
		uf.init();
		cur = 0;

		for (int tid = 0; tid < q; tid ++) {
			for (auto &u: tmp[tid]) {
				col[u] = 1;
				for (auto &v: path[u]) {
					if (col[v] == 1) {
						int fu = uf.leader(u), fv = uf.leader(v);

						int nu = us[fu], nv = vs[fu], nd = ds[fu];
						if (ds[fv] > ds[fu])
							nu = us[fv], nv = vs[fv], nd = ds[fv];
						
						for (auto &x: {us[fu], vs[fu]}) {
							for (auto &y: {us[fv], vs[fv]}) {
								int d = dis(x, y);
								if (d > nd)
									nu = x, nv = y, nd = d;
							}
						}

						uf.merge(u, v);
						fu = uf.leader(u);

						us[fu] = nu, vs[fu] = nv, ds[fu] = nd;
						cur = max(cur, nd);
					}
				}
			}
			ans[tid] = cur;
		}
			
		iota(us.begin(), us.end(), 0);
		iota(vs.begin(), vs.end(), 0);
		fill(ds.begin(), ds.end(), 0);
		fill(col.begin(), col.end(), 0);
		uf.init();
		cur = 0;

		for (int tid = q - 1; tid >= 0; tid --) {
			for (auto &u: tmp[tid + 1]) {
				col[u] = 1;
				for (auto &v: path[u]) {
					if (col[v] == 1) {
						int fu = uf.leader(u), fv = uf.leader(v);

						int nu = us[fu], nv = vs[fu], nd = ds[fu];
						if (ds[fv] > ds[fu])
							nu = us[fv], nv = vs[fv], nd = ds[fv];
						
						for (auto &x: {us[fu], vs[fu]}) {
							for (auto &y: {us[fv], vs[fv]}) {
								int d = dis(x, y);
								if (d > nd)
									nu = x, nv = y, nd = d;
							}
						}

						uf.merge(u, v);
						fu = uf.leader(u);

						us[fu] = nu, vs[fu] = nv, ds[fu] = nd;
						cur = max(cur, nd);
					}
				}
			}
			ans[tid] = max(ans[tid], cur);
		}

		for (auto &x: ans) cout << x + 1 << '\n';
	}

	return 0;
}