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

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	vector<vector<int>> path(n);
	vector<int> indeg(n, 0);

	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		indeg[v] ++;
	}

	vector<int> depth(n, 0), stk;

	for (int i = 0; i < n; i ++) {
		if (!indeg[i]) {
			stk.emplace_back(i);
		}
	}

	while (!stk.empty()) {
		int u = stk.back(); stk.pop_back();

		for (auto &v: path[u]) {
			depth[v] = max(depth[v], depth[u] + 1);
			indeg[v] --;

			if (!indeg[v]) stk.emplace_back(v);
		}
	}

	if (*max_element(depth.begin(), depth.end()) >= 67 || *max_element(indeg.begin(), indeg.end()))
		cout << "NO\n";
	else {
		cout << "YES\n";
		while (m --) cout << s[0] << '\n';
	}

	return 0;
}