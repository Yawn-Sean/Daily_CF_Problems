#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<vector<pair<int, int>>> pos(2 * n + 1);

		for (int i = 0; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			pos[x].emplace_back(i, 0);
			pos[y].emplace_back(i, 1);
		}

		bool flg = true;
		atcoder::dsu uf(2 * n);

		for (int i = 0; i <= 2 * n; i ++) {
			if (pos[i].size() > 2) flg = false;
			else if (pos[i].size() == 2) {
				auto [idx1, f1] = pos[i][0];
				auto [idx2, f2] = pos[i][1];
				if (f1 != f2) {
					uf.merge(idx1, idx2);
					uf.merge(idx1 + n, idx2 + n);
				}
				else {
					uf.merge(idx1, idx2 + n);
					uf.merge(idx1 + n, idx2);
				}
			}
		}

		for (int i = 0; i < n; i ++) {
			if (uf.leader(i) == uf.leader(i + n)) {
				flg = false;
			}
		}

		if (!flg) cout << -1 << '\n';
		else {
			vector<int> cnt(n, 0), cnt1(n, 0);
			for (int i = 0; i < 2 * n; i ++) {
				if (uf.leader(i) < n) {
					cnt[uf.leader(i)] ++;
					if (i < n) cnt1[uf.leader(i)] ++;
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i ++)
				ans += min(cnt1[i], cnt[i] - cnt1[i]);
			
			cout << ans << '\n';
		}
	}

	return 0;
}