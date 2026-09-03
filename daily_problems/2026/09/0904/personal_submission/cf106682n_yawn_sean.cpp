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

int factorial(int x, int mod) {
	int res = 1;
	for (int i = 1; i <= x; i ++) {
		res = 1ll * res * i % mod;
	}
	return res;
}

int ifactorial(int x, int mod) {
	return quickPow(factorial(x, mod), mod - 2, mod);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, a, mod = 998244353;
	cin >> n >> k >> a;

	if (n == 1) {
		if (k) cout << 0;
		else cout << a;
	}
	else if (n == 2) {
		if (k) cout << 0;
		else cout << a * a;
	}
	else {
		if (k > n - 2) cout << 0;
		else cout << 1ll * a * a * factorial(n - 2, mod) % mod * ifactorial(k, mod) % mod * ifactorial(n - 2 - k, mod) % mod * quickPow(a - 1, n - 2 - k, mod) % mod;
	}

	return 0;
}