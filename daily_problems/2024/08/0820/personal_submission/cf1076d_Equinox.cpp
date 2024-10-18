#include <bits/stdc++.h>
#include <ranges>

using i64 = long long;
using i32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1'000'000'007;

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::vector<int>> g(n);
	std::vector<std::array<int, 2>> edges;
	
	for (int i = 0, u, v, w; i < m; ++ i) {
		std::cin >> u >> v >> w;
		-- u, -- v;
		g[u].push_back(edges.size());
		edges.push_back({v, w});
		g[v].push_back(edges.size());
		edges.push_back({u, w});	
	}

	std::vector<i64> dst(n, inf64);
	std::vector<int> pre(n, -1);

	std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;

	pq.emplace(dst[0] = 0, 0);

	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();

		if (d > dst[u]) continue;

		for (int i : g[u]) {
			auto [v, w] = edges[i];
			if (d + w < dst[v]) {
				pre[v] = i;
				pq.emplace(dst[v] = d + w, v);
			}
		}
	}

	int ans = std::min(k, n - 1);

	std::cout << ans << '\n';

	std::vector<int> st(n - 1);
	std::iota(st.begin(), st.end(), 1);

	std::ranges::sort(st, [&dst](int u, int v) -> bool{
		return dst[u] < dst[v];
	});

	for (int i = 0; i < ans; ++ i) {
		std::cout << pre[st[i]] / 2 + 1 << " \n"[i + 1 == ans];
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