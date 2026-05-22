#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> n >> t;

	vector<int> pr(n), pc(n);

	iota(pr.begin(), pr.end(), 0);
	iota(pc.begin(), pc.end(), 0);

	while (t --) {
		char c; int i, j;
		cin >> c >> i >> j;
		i --, j --;
		if (c == 'R') swap(pr[i], pr[j]);
		else swap(pc[i], pc[j]);
	}

	vector<int> vis_r(n, 0), vis_c(n, 0);
	vector<vector<int>> groups_r, groups_c;

	for (int i = 0; i < n; i ++) {
		if (!vis_r[i]) {
			int cur = i;
			vector<int> group;

			while (!vis_r[cur]) {
				vis_r[cur] = 1;
				group.emplace_back(cur);
				cur = pr[cur];
			}

			groups_r.emplace_back(group);
		}
	}

	for (int i = 0; i < n; i ++) {
		if (!vis_c[i]) {
			int cur = i;
			vector<int> group;

			while (!vis_c[cur]) {
				vis_c[cur] = 1;
				group.emplace_back(cur);
				cur = pc[cur];
			}

			groups_c.emplace_back(group);
		}
	}

	int m = groups_r.size(), k = groups_r[0].size();

	for (auto &x: groups_r) {
		if (x.size() != k) {
			return cout << '*', 0;
		}
	}

	for (auto &x: groups_c) {
		if (x.size() != k) {
			return cout << '*', 0;
		}
	}

	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < m; j ++) {
			int start = (i + j) % m * k + 1;

			for (int di = 0; di < k; di ++) {
				for (int dj = 0; dj < k; dj ++) {
					ans[groups_r[i][di]][groups_c[j][dj]] = start + (di - dj + k) % k;
				}
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << ans[i][j] << " \n"[j == n - 1];
		}
	}

	return 0;
}