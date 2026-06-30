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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 3e5 + 5, mod = 998244353;
	vector<int> invs(M);
	
	invs[1] = 1;
	for (int i = 2; i < M; i ++)
		invs[i] = 1ll * (mod - mod / i) * invs[mod % i] % mod;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> edges(n);
		vector<int> nodes;

		for (auto &[u, v]: edges) {
			cin >> u >> v;
			nodes.emplace_back(u);
			nodes.emplace_back(v);
		}

		sort(nodes.begin(), nodes.end());

		atcoder::dsu uf(2 * n);
		vector<int> tag(2 * n, 0);

		int ans = 1;

		for (int i = 0; i < n; i ++) {
			int u = lower_bound(nodes.begin(), nodes.end(), edges[i].first) - nodes.begin();
			int v = lower_bound(nodes.begin(), nodes.end(), edges[i].second) - nodes.begin();

			u = uf.leader(u), v = uf.leader(v);
			int szu = uf.size(u), szv = uf.size(v);

			uf.merge(u, v);
			int p = uf.leader(u);

			if (u != v) {
				if (tag[u] && tag[v]) ans = 0;
				else if (tag[u]) {
					ans = 1ll * ans * invs[szv] % mod;
					tag[p] = 1;
				}
				else if (tag[v]) {
					ans = 1ll * ans * invs[szu] % mod;
					tag[p] = 1;
				}
				else {
					ans = 1ll * ans * invs[szu] % mod * invs[szv] % mod * (szu + szv) % mod;
				}
			}
			else {
				if (tag[u]) ans = 0;
				else {
					ans = 2ll * ans * invs[szu] % mod;
					tag[u] = 1;
				}
			}

			cout << ans << " \n"[i == n - 1];
		}
	}

	return 0;
}