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

	int n, k, mod = 998244353;
	cin >> n >> k;

	int ans = 0, cur_len = 1, cur_len1 = 1;

	while (n --) {
		cur_len = cur_len * 2 % mod;
		cur_len1 = cur_len1 * 2 % (mod - 1);

		int a = 1, b = quickPow(k, cur_len1, mod) % mod;

		for (int i = 1; i < k; i ++) {
			a = 1ll * a * (k + cur_len - i) % mod;
			b = 1ll * b * i % mod;
		}

		int prob = (mod + 1 - a * quickPow(b, mod - 2, mod) % mod) % mod;
		ans = (ans + prob) % mod;
	}

	cout << ans;

	return 0;
}