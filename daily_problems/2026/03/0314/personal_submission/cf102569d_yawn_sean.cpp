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

	vector<vector<pair<int, char>>> path(n + 1);

	while (m --) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		path[u].emplace_back(v, c);
		path[v].emplace_back(u, c);
	}

	vector<int> dis(n + 1, -1);
	dis[n] = 0;

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &[v, c]: path[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	vector<int> cur = {1}, parent(n + 1, -1);
	string ans;

	while (cur[0] != n) {
		char min_ch = 'z';
		for (auto &u: cur) {
			for (auto &[v, c]: path[u]) {
				if (dis[v] == dis[u] - 1) {
					min_ch = min(min_ch, c);
				}
			}
		}
		vector<int> ncur;
		ans += min_ch;
		for (auto &u: cur) {
			for (auto &[v, c]: path[u]) {
				if (dis[v] == dis[u] - 1 && min_ch == c && parent[v] == -1) {
					ncur.emplace_back(v);
					parent[v] = u;
				}
			}
		}
		cur.swap(ncur);
	}

	cout << ans.size() << '\n';

	vector<int> route = {n};
	while (route.back() != 1)
		route.emplace_back(parent[route.back()]);
	reverse(route.begin(), route.end());

	for (auto &x: route) cout << x << ' '; cout << '\n';

	cout << ans;

	return 0;
}