#include <bits/stdc++.h>
#define int long long
namespace cc {
	using namespace std;
	using i128 = __int128;
	using pii = array<int, 2>;
	constexpr int inf = 1e18;
}
using namespace cc;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> adj1(n), adj2(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj1[u].push_back({v, w});
		adj2[v].push_back({u, w});
	}

	auto work = [&](vector<vector<pii>> &adj) {
		vector<int> dis(n, inf);
		priority_queue<pii, vector<pii>, greater<pii>> q;

		dis[0] = 0;
		q.push({0, 0});
		while (q.size()) {
			auto [d, u] = q.top();
			q.pop();
			if (dis[u] != d) continue;
			for (auto &[v, w] : adj[u]) {
				if (dis[v] > max(d, w)) {
					dis[v] = max(d, w);
					q.push({dis[v], v});
				}
			}
		}
		return dis;
	};

	auto to = work(adj1);
	auto fr = work(adj2);

	for (int i = 0; i < n; i++) {
		if (to[i] < fr[i]) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);

	solve();
	
	return 0;
}