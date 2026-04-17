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

	int M = 1e6 + 5, mod = 998244353;

	vector<int> f(n + 1), g(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --) g[i - 1] = 1ll * i * g[i] % mod;

	vector<int> cnt(M, 0);
	int mi = M, ma = 0;

	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		mi = min(x, mi);
		ma = max(x, ma);
		cnt[x] ++;
	}

	int ans = f[cnt[mi]], neighbors = cnt[mi];

	for (int i = mi + 1; i <= ma; i ++) {
		if (cnt[i] < neighbors) {
			ans = 0;
			break;
		}

		ans = 1ll * ans * f[cnt[i]] % mod * f[cnt[i] - 1] % mod * g[neighbors - 1] % mod * g[cnt[i] - neighbors] % mod;

		neighbors = cnt[i] - neighbors;
	}

	if (!neighbors) cout << 1ll * ans * n % mod * f[cnt[mi] - 1] % mod * g[cnt[mi]] % mod;
	else cout << 0;

	return 0;
}