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

	int mod = 1e9 + 7;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int total = 1ll * (n - 1) * (n - 2) / 2 % mod;
		int valid = 1ll * (n / 2) * (n / 2 - 1) / 2 % mod * 3 % mod;

		cout << 1ll * (mod + total - valid) % mod * quickPow(total, mod - 2, mod) % mod << '\n';
	}

	return 0;
}