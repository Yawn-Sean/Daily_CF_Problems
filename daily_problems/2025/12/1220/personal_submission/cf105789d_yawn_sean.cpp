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

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<pair<int, int>> edges(m);
	for (auto &[u, v]: edges) {
		cin >> u >> v;
		u --, v --;
	}

	sort(edges.begin(), edges.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
		return max(nums[x.first], nums[x.second]) < max(nums[y.first], nums[y.second]);
	});

	atcoder::dsu uf(n);
	vector<vector<int>> path(2 * n - 1);
	vector<int> notes(n);
	
	iota(notes.begin(), notes.end(), 0);
	int pt = n;

	for (auto &[u, v]: edges) {
		if (uf.leader(u) != uf.leader(v)) {
			path[pt].emplace_back(notes[uf.leader(u)]);
			path[pt].emplace_back(notes[uf.leader(v)]);
			uf.merge(u, v);
			notes[uf.leader(u)] = pt;
			pt ++;
		}
	}

	vector<int> val(2 * n - 1, 0), sz(2 * n - 1, 0);

	auto dfs1 = [&] (auto &self, int u) -> void {
		if (u < n) sz[u] = 1, val[u] = nums[u];
		for (auto &v: path[u]) {
			self(self, v);
			sz[u] += sz[v];
			val[u] = max(val[u], val[v]);
		}
	};

	dfs1(dfs1, 2 * n - 2);

	vector<long long> ans(2 * n - 1, 0);

	auto dfs2 = [&] (auto &self, int u) -> void {
		if (u < n) ans[u] += nums[u];
		for (auto &v: path[u]) {
			ans[v] = ans[u] + 1ll * (sz[u] - sz[v]) * val[u];
			self(self, v);
		}
	};

	dfs2(dfs2, 2 * n - 2);

	for (int i = 0; i < n; i ++) cout << ans[i] << ' ';

	return 0;
}