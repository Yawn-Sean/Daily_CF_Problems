#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<pair<int, int>> pts(k + 1);
		for (auto &[x, y]: pts) {
			cin >> x >> y;
			x --, y --;
		}

		bool flg = true;
		for (int i = 0; i < k; i ++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[i + 1];
			if (abs(x1 - x2) + abs(y1 - y2) != 2) flg = false;
		}

		if (!flg) cout << 0 << '\n';
		else {
			atcoder::dsu uf(n * m);
			vector<int> edge_cnt(n * m, 0), self_cycle(n * m, 0);

			auto f = [&] (int x, int y) -> int {return x * m + y;};

			for (int i = 0; i < k; i ++) {
				auto [x1, y1] = pts[i];
				auto [x2, y2] = pts[i + 1];
				
				if (x1 == x2 || y1 == y2) {
					int msk = f((x1 + x2) / 2, (y1 + y2) / 2);
					edge_cnt[msk] ++;
					self_cycle[msk] = 1;
				}
				else {
					int msk1 = f(x1, y2);
					int msk2 = f(x2, y1);
					uf.merge(msk1, msk2);
					edge_cnt[msk1] ++;
				}
			}

			for (int i = 0; i < n * m; i ++) {
				if (uf.leader(i) != i) {
					edge_cnt[uf.leader(i)] += edge_cnt[i];
					self_cycle[uf.leader(i)] |= self_cycle[i];
				}
			}

			int ans = 1;
			for (int i = 0; i < n * m; i ++) {
				if (uf.leader(i) == i) {
					if (edge_cnt[i] > uf.size(i)) ans = 0;
					else if (edge_cnt[i] == uf.size(i)) {
						if (!self_cycle[i]) ans = 2 * ans % mod;
					}
					else ans = 1ll * uf.size(i) * ans % mod;
				}
			}

			cout << ans << '\n';
		}
	}

	return 0;
}