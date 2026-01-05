#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
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

	vector<int> f(1001), g(1001);
	f[0] = 1;
	for (int i = 1; i <= 1000; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;
	g[1000] = quickPow(f[1000], mod - 2, mod);
	for (int i = 1000; i >= 1; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	int rev26 = quickPow(26, mod - 2, mod);
	vector<int> pw_rev26(1001);
	pw_rev26[0] = 1;
	for (int i = 1; i <= 1000; i ++)
		pw_rev26[i] = 1ll * pw_rev26[i - 1] * rev26 % mod;

	int t;
	cin >> t;

	while (t --) {
		string s;
		cin >> s;

		vector<int> cnt(26, 0);
		int to_fill = 0;

		for (auto &c: s) {
			if (c >= 'a' && c <= 'z') cnt[c - 'a'] ++;
			else to_fill ++;
		}

		vector<int> dp(to_fill + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < 26; i ++) {
			for (int j = to_fill; j >= 0; j --) {
				if (dp[j]) {
					for (int k = 1; k <= to_fill - j; k ++) {
						dp[j + k] = (dp[j + k] + 1ll * dp[j] * g[cnt[i] + k] % mod * g[k] % mod) % mod;
					}
					dp[j] = 1ll * dp[j] * g[cnt[i]] % mod;
				}
			}
		}

		cout << 1ll * dp[to_fill] * f[to_fill] % mod * f[s.size()] % mod * pw_rev26[to_fill] % mod << '\n';
	}

	return 0;
}