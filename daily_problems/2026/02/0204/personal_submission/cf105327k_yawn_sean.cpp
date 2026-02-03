#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	atcoder::dsu uf(n + m);
	vector<vector<int>> path(n + m);

	for (int i = 0; i < n; i ++) {
		int k;
		cin >> k;

		while (k --) {
			int u;
			cin >> u;
			u --;

			if (uf.merge(u, m + i)) {
				path[u].emplace_back(m + i);
				path[m + i].emplace_back(u);
			}
		}
	}

	vector<int> parent(n + m, -1), depth(n + m, 0);

	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				parent[v] = u;
				depth[v] = depth[u] + 1;
				self(self, v, u);
			}
		}
	};

	for (int i = 0; i < n + m; i ++) {
		if (parent[i] == -1) {
			dfs(dfs, i, -1);
		}
	}

	int q;
	cin >> q;

	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		if (uf.leader(u) != uf.leader(v)) cout << "-1\n";
		else {
			vector<int> path_u = {u}, path_v = {v};

			while (path_u.back() != path_v.back()) {
				if (depth[path_u.back()] > depth[path_v.back()])
					path_u.emplace_back(parent[path_u.back()]);
				else path_v.emplace_back(parent[path_v.back()]);
			}

			path_u.insert(path_u.end(), path_v.rbegin() + 1, path_v.rend());
			cout << path_u.size() / 2 + 1 << '\n';

			for (auto &x: path_u) cout << (x < m ? x + 1 : x - m + 1) << ' ';
			cout << '\n';
		}
	}

	return 0;
}