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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<vector<int>> acc(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j]) {
				acc[i + 1][j + 1] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j < m; j ++) {
			acc[i][j + 1] += acc[i][j];
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= m; j ++) {
			acc[i + 1][j] += acc[i][j];
		}
	}

	vector<vector<int>> next_pos(n, vector<int>(m + 1, m));

	for (int i = 0; i < n; i ++) {
		for (int j = m - 1; j >= 0; j --) {
			next_pos[i][j] = next_pos[i][j + 1];
			if (grid[i][j]) next_pos[i][j] = j;
		}
	}

	auto calc = [&] (int x1, int y1, int x2, int y2) -> int {
		x2 ++, y2 ++;
		return acc[x1][y1] - acc[x1][y2] - acc[x2][y1] + acc[x2][y2];
	};

	int q;
	cin >> q;

	while (q --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 --, y1 --, x2 --, y2 --;

		int pt = x1;
		vector<int> tmp;

		while (tmp.size() <= 30) {
			int l = pt, r = x2;

			while (l <= r) {
				int mid = (l + r) / 2;
				if (calc(pt, y1, mid, y2)) r = mid - 1;
				else l = mid + 1;
			}

			if (l > x2) break;

			int cur = y1;
			while (next_pos[l][cur] <= y2) {
				cur = next_pos[l][cur];
				tmp.emplace_back(grid[l][cur]);
				if (tmp.size() > 30) break;
				cur ++;
			}

			pt = l + 1;
		}

		if (tmp.size() > 30) cout << "YES\n";
		else {
			sort(tmp.begin(), tmp.end());
			bool flg = false;
			for (int i = 2; i < tmp.size(); i ++) {
				if (tmp[i - 2] + tmp[i - 1] > tmp[i]) {
					flg = true;
					break;
				}
			}
			cout << (flg ? "YES\n" : "NO\n");
		}
	}

	return 0;
}