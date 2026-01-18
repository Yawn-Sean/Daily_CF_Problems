#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	atcoder::dsu uf1(n), uf2(n);

	for (int i = 0; i < m; i ++) {
		auto [u, v, w] = edges[i];
		if (w % 2 == 0) uf1.merge(u, v);
	}

	vector<int> ans(m, 0);
	int even = 1;

	for (int i = 0; i < m; i ++) {
		auto [u, v, w] = edges[i];
		if (w % 2 && uf1.merge(u, v)) {
			uf2.merge(u, v);
			ans[i] = 1;
			even ^= 1;
		}
	}

	if (!even) {
		for (int i = 0; i < m; i ++) {
			auto [u, v, w] = edges[i];
			if (w % 2 && !ans[i] && uf2.merge(u, v)) {
				ans[i] = 1;
				even ^= 1;
				break;
			}
		}
	}

	if (!even) cout << "NO";
	else {
		for (int i = 0; i < m; i ++) {
			auto [u, v, w] = edges[i];
			if (w % 2 == 0 && uf2.merge(u, v))
				ans[i] = 1;
		}

		cout << "YES\n";
		for (int i = 0; i < m; i ++)
			if (ans[i]) cout << i + 1 << ' ';
	}

	return 0;
}