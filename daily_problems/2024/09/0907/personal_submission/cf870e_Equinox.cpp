#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1E9 + 7;

int power (int a, i64 b, int p) {
    int res = 1;
    for (; b; b >>= 1, a = 1LL * a * a % p)
        if (b & 1)
            res = 1LL * res * a % p;
    return res;
}

void solve(){
	int n;
	std::cin >> n;

	std::map<i64, std::vector<i64>> adj;

	int base = 2E9;

	for (int i = 0; i < n; ++ i) {
		i64 u, v;
		std::cin >> u >> v;
		v += base;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::set<i64> vis;
	int cnt = 0;
	auto dfs = [&](auto &&self, i64 u, i64 p) -> bool {
		bool res = false;
		vis.insert(u);
		++ cnt;
		for (i64 v : adj[u]) {
			if (v == p) continue;
			if (!vis.contains(v)) {
				res = res || self(self, v, u);
			}
			else {
				res = true;
			}
		}
		return res;
	};

	int res = 1;

	for (auto &[u, e] : adj) {
		if (vis.contains(u)) continue;
		cnt = 0;
		bool ok = dfs(dfs, u, -1);
		res = 1LL * res * (power(2, cnt, P) - !ok) % P;
	}

	std::cout << res << '\n';
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}