#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int mod = 998244353, M = 1e5 + 5;

	vector<int> f(M), g(M);

	f[0] = 1;
	for (int i = 1; i < M; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);
	for (int i = M - 1; i > 0; i --) g[i - 1] = 1ll * i * g[i] % mod;
	
	auto comb = [&] (int x, int y) -> int {
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	vector<int> acc(m + 2, 0);
	int pw = 1;

	for (int i = m; i >= 0; i --) {
		int cur = 1ll * pw * comb(m, i) % mod;
		pw = 1ll * pw * (n - 1) % mod;
		acc[i + 1] = cur;
	}

	for (int i = 1; i <= m + 1; i ++) acc[i] = (acc[i] + acc[i - 1]) % mod;

	int rev_total = quickPow(quickPow(n, mod - 2, mod), m, mod);

	for (int i = 0; i <= m + 1; i ++) acc[i] = 1ll * acc[i] * rev_total % mod;

	vector<int> ans(10, 0);

	while (n --) {
		int x;
		cin >> x;

		for (int i = 1; i < 10; i ++) {
			int l = i, r = i;

			for (int j = 0; j < 6; j ++) {
				int vl = max(0, l - x);
				int vr = min(m, r - x);

				l = l * 10;
				r = r * 10 + 9;

				if (vl > vr) continue;

				ans[i] += acc[vr + 1];
				ans[i] %= mod;

				ans[i] += mod - acc[vl];
				ans[i] %= mod;
			}
		}
	}

	for (int i = 1; i < 10; i ++)
		cout << ans[i] << '\n';

	return 0;
}