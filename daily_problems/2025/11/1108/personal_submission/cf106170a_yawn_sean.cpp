#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

	int n;
	cin >> n;

	vector<pair<int, int>> edges(n - 1);
	vector<vector<int>> path(n);

	for (auto &[u, v]: edges) {
		cin >> u >> v;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	auto dis = [&] (int start) -> vector<int> {
		vector<int> ans(n, -1);
		ans[start] = 0;

		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			auto u = q.front(); q.pop();
			for (auto &v: path[u]) {
				if (ans[v] == -1) {
					ans[v] = ans[u] + 1;
					q.push(v);
				}
			}
		}

		return ans;
	};

	auto d = dis(0);
	int diameter_u = max_element(d.begin(), d.end()) - d.begin();
	auto d1 = dis(diameter_u);
	int diameter_v = max_element(d1.begin(), d1.end()) - d1.begin();
	auto d2 = dis(diameter_v);

	int ans = n, chosen = -1;

	for (int i = 0; i < n; i ++) {
		if (path[i].size() == 1) {
			int v = max(d1[i], d2[i]);
			if (v < ans) {
				ans = v;
				chosen = i;
			}
		}
	}

	vector<int> cur = {diameter_v};

	while (cur.back() != diameter_u) {
		for (auto &v: path[cur.back()]) {
			if (d1[cur.back()] - d1[v] == 1) {
				cur.emplace_back(v);
				break;
			}
		}
	}

	int k = cur.size();
	vector<int> notes(n, -1), find_leaf(n);
	int idx = cur[k / 2];
	notes[idx] = k / 2;

	iota(find_leaf.begin(), find_leaf.end(), 0);

	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				notes[v] = notes[u] + (d1[v] >= d2[v] ? -1 : 1);
				self(self, v, u);
				find_leaf[u] = find_leaf[v];
			}
		}
	};

	dfs(dfs, idx, -1);

	cout << ans << '\n';
	for (auto &[u, v]: edges) {
		if (notes[u] > notes[v]) swap(u, v);

		int leaf = (d1[u] >= d2[u] ? find_leaf[u] : find_leaf[v]);
		int other_end = (notes[leaf] >= ans ? cur[notes[leaf] - ans] : cur[notes[leaf] + ans]);
		cout << notes[u] % ans << ' ' << leaf << ' ' << other_end << '\n';
	}

	return 0;
}