#include <bits/stdc++.h>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 998'244'353;

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	std::vector<int> in(n), st(n), vis(n), bel(n, -1), ans;

	for (int i = 0, u, v; i < m; ++ i) {
		std::cin >> u >> v;
		-- u, -- v;
		adj[u].push_back(v);
		++ in[v];
	}

	for (int i = 0; i < n; ++ i)
		std::cin >> st[i], vis[-- st[i]] = 1;

	std::vector<int> stk;

	for (int i = 0; i < n; ++ i)
		if (!in[i])
			stk.push_back(i);

	while (stk.size()) {
		int u = stk.back();
		stk.pop_back();
		if (vis[u]) {
			ans.push_back(u);
			bel[u] = u;
		}
		for (int v : adj[u]) {
			bel[v] = bel[u];
			stk.push_back(v);
		}
	}

	if (bel != st)
		std::cout << "-1";
	else {
		std::reverse(ans.begin(), ans.end());
		std::cout << ans.size() << '\n';
		for (int x : ans)
			std::cout << x + 1 << '\n';
	}
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main () {
	#ifdef DEBUG
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int T = 1;
	// std::cin >> T;
	while (T --)
		solve();

	return 0;
}