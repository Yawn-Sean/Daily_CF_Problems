#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> path(n);

	for (int i = 0; i < n - 1; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --, v --;
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}

	vector<int> tag(n, 0);

	int m;
	cin >> m;

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		tag[u] ^= 1;
		tag[v] ^= 1;
	}

	long long ans = 0;

	auto dfs = [&] (auto &self, int u, int p) -> int {
		int ret = tag[u];

		for (auto &[v, w]: path[u]) {
			if (v != p && self(self, v, u)) {
				ans += w;
				ret ^= 1;
			}
		}

		return ret;
	};

	dfs(dfs, 0, -1);

	cout << ans;

	return 0;
}