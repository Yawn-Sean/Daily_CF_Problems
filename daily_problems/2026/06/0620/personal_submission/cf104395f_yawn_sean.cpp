#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, mod = 1e9 + 7;
	cin >> n >> m;

	atcoder::dsu uf(n);
	int ans = 0;

	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		if (!uf.merge(u, v)) ans ++;
	}

	for (int i = 1; i <= n - m; i ++) {
		ans += quickPow(i, mod - 2, mod);
		ans %= mod;
	}

	cout << ans;

	return 0;
}