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
	int n;
	cin >> n;
	vector<vector<pii>> adj(n);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<int> dp1(n), dp2(n), sub(n);
	auto dfs1 = [&](this auto &&self, int u, int fa) -> void {
		for (auto &[v, w] : adj[u]) {
			if (v == fa) continue;
			self(v, u);
			int p = dp1[v] + w;
			if (p > dp1[u]) {
				dp2[u] = dp1[u];
				dp1[u] = p;
			} else if (p > dp2[u]) {
				dp2[u] = p;
			}
			sub[u] = max(sub[u], sub[v]);
		}
		sub[u] = max(sub[u], dp1[u] + dp2[u]);
	};
	dfs1(0, -1);

	vector<int> els(n);
	auto dfs2 = [&](this auto &&self, int u, int fa) -> void {
		int p1 = 0, p2 = 0, p3 = 0;
		int s1 = 0, s2 = 0;
		for (auto &[v, w] : adj[u]) {
			int p = dp1[v] + w, s = sub[v];
			if (p > p1) {
				p3 = p2;
				p2 = p1;
				p1 = p;
			} else if (p > p2) {
				p3 = p2;
				p2 = p;
			} else if (p > p3) {
				p3 = p;
			}
			if (s > s1) {
				s2 = s1;
				s1 = s;
			} else if (s > s2) {
				s2 = s;
			}
		}

		for (auto &[v, w] : adj[u]) {
			if (v == fa) continue;
			
			auto bak = array<int, 6>{dp1[u], dp2[u], sub[u], dp1[v], dp2[v], sub[v]};

			int p = dp1[v] + w, s = sub[v];
			if (p == dp1[u]) {
				dp1[u] = dp2[u];
				dp2[u] = p3;
			} else if (p == dp2[u]) {
				dp2[u] = p3;
			}
			if (s == s1) {
				sub[u] = s2;
			} else {
				sub[u] = s1;
			}
			sub[u] = max(sub[u], dp1[u] + dp2[u]);
			
			els[v] = sub[u];

			int np = dp1[u] + w;
			if (np > dp1[v]) {
				dp2[v] = dp1[v];
				dp1[v] = np;
			} else if (np > dp2[v]) {
				dp2[v] = np;
			}
			sub[v] = max({sub[v], sub[u], dp1[v] + dp2[v]});

			self(v, u);

			tie(dp1[u], dp2[u], sub[u], dp1[v], dp2[v], sub[v]) = bak;
		}
	};
	dfs2(0, -1);

	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans = max(ans, min(sub[i], els[i]));
	}
	cout << ans << '\n';
}

signed main() {
	cin.tie(0) -> sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}