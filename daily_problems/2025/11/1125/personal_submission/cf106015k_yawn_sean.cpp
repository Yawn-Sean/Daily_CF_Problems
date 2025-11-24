#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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


using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<array<int, 3>> edges(m);

	for (auto &[u, v, w]: edges) {
		cin >> u >> v >> w;
		u --, v --;
	}

	sort(edges.begin(), edges.end(), [&](array<int, 3> &x, array<int, 3> &y) {return x[2] < y[2];});

	atcoder::dsu uf(n);
	vector<array<int, 3>> to_check;
	vector<vector<pair<int, int>>> path(n);

	for (auto &[u, v, w]: edges) {
		if (uf.merge(u, v)) {
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}
		else to_check.push_back({u, v, w});
	}

	vector<int> depth(n, 0);
	vector<long long> to_root(n, 0);
	vector<vector<int>> nth_parent(20, vector<int>(n, -1));

	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &[v, w]: path[u]) {
			if (v != p) {
				depth[v] = depth[u] + 1;
				to_root[v] = to_root[u] + w;
				nth_parent[0][v] = u;
				self(self, v, u);
			}
		}
	};

	dfs(dfs, 0, -1);

	for (int i = 0; i < 19; i ++) {
		for (int j = 0; j < n; j ++) {
			if (nth_parent[i][j] >= 0) {
				nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
			}
		}
	}

	auto lca = [&] (int u, int v) -> int {
		if (depth[u] > depth[v]) swap(u, v);

		int d = depth[v] - depth[u];
		while (d) {
			int x = d & -d;
			v = nth_parent[__builtin_ctz(x)][v];
			d -= x;
		}

		if (u == v) return u;

		for (int i = 19; i >= 0; i --) {
			if (nth_parent[i][u] != nth_parent[i][v]) {
				u = nth_parent[i][u];
				v = nth_parent[i][v];
			}
		}

		return nth_parent[0][u];
	};

	for (auto &[u, v, w]: to_check) {
		int l = lca(u, v);
		if (to_root[u] + to_root[v] - 2 * to_root[l] > w)
			return cout << "NO", 0;
	}

	cout << "YES";

	return 0;
}