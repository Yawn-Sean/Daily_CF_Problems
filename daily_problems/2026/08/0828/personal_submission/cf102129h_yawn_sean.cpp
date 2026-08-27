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

	int t, mod = 1e9 + 7;
	cin >> t;

	auto sqrt_int = [&] (long long val) -> long long {
		long long l = 0, r = 2e9;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (mid * mid <= val) l = mid + 1;
			else r = mid - 1;
		}
		return r;
	};

	while (t --) {
		long long m;
		cin >> m;
		long long v = (2 * m + 1 - sqrt_int(2 * m * m + 2 * m + 1)) / 2;

		for (long long k = v - 1; k <= v; k ++) {
			if (k == m) continue;
			long long A = m * m + m - 2 * (k * k + k);
			long long B = 4 * (m - k);
			if (A / B == k) {
				A %= mod;
				B %= mod;
				cout << A * quickPow(B, mod - 2, mod) % mod << '\n';
				break;
			}
		}
	}

	return 0;
}