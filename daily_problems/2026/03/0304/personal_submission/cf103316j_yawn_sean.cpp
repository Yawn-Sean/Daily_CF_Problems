#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

	int ans = 0, mod = 1e9 + 7;

	atcoder::dsu uf(n);
	vector<int> vis(n, 0);

	for (auto &u: order) {
		for (auto &v: path[u]) {
			if (vis[v]) {
				ans += 1ll * nums[u] * uf.size(u) % mod * uf.size(v) % mod;
				ans %= mod;
				uf.merge(u, v);
			}
		}
		vis[u] = 1;
	}

	reverse(order.begin(), order.end());

	uf.init();
	fill(vis.begin(), vis.end(), 0);

	for (auto &u: order) {
		for (auto &v: path[u]) {
			if (vis[v]) {
				ans += mod - 1ll * nums[u] * uf.size(u) % mod * uf.size(v) % mod;
				ans %= mod;
				uf.merge(u, v);
			}
		}
		vis[u] = 1;
	}

	cout << 1ll * ans * quickPow(1ll * n * (n - 1) / 2 % mod, mod - 2, mod) % mod;

	return 0;
}