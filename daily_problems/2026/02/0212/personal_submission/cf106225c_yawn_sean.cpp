#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> lsts(n, vector<int>(m));
		for (auto &x: lsts) for (auto &y: x) cin >> y;

		if (n % 2 == 0) {
			vector<int> vis(n * m / 2 + 1, 0);
			for (auto &x: lsts) {
				if (vis[x[0]]) continue;
				for (auto &v: x) cout << v << ' ';
				vis[x[0]] = 1;
			}
		}
		else {
			vector<int> next_pos(n * m / 2 + 1, 0);
			vector<int> idxs(n * m / 2 + 1, 0);

			for (int i = 0; i < n; i ++) {
				next_pos[lsts[i][0]] = lsts[i][m / 2];
				idxs[lsts[i][0]] = i;
			}

			int cur = lsts[0][0];
			for (int j = 0; j < n; j ++) {
				for (int k = 0; k < m / 2; k ++) {
					cout << lsts[idxs[cur]][k] << ' ';
				}
				cur = next_pos[cur];
			}
		}
		cout << '\n';
	}

	return 0;
}