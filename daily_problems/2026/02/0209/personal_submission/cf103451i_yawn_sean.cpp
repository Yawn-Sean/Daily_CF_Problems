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

	long long n;
	cin >> n;

	string and_val, or_val, xor_val;
	cin >> and_val >> or_val >> xor_val;

	int k = and_val.size();
	int ans = 1, mod = 1e9 + 7;

	int saved = quickPow(2, n - 1, mod);

	for (int i = 0; i < k; i ++) {
		int res = 0;
		if (and_val[i] == '1') {
			if (or_val[i] == '1' && n % 2 == xor_val[i] - '0') {
				res = 1;
			}
		}
		else {
			if (or_val[i] == '0') {
				if (xor_val[i] == '0') {
					res = 1;
				}
			}
			else {
				if (n >= 2) {
					res = saved;
					if (xor_val[i] == '0') res = (res + mod - 1) % mod;
					if (n % 2 == xor_val[i] - '0') res = (res + mod - 1) % mod;
				}
			}
		}

		ans = 1ll * ans * res % mod;
	}

	cout << ans;

	return 0;
}