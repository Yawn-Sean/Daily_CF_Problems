#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> probs(n + 1, 1);

		for (int i = 0; i < n; i ++) {
			int a, p, q;
			cin >> a >> p >> q;
			probs[a] = 1ll * probs[a] * (q - p) % mod * quickPow(q, mod - 2, mod) % mod;
		}

		int ans = 0, cur = 1;

		for (int i = 0; i <= n; i ++) {
			cur = 1ll * cur * (mod + 1 - probs[i]) % mod;
			ans = (ans + cur) % mod;
		}

		cout << ans << '\n';
	}

	return 0;
}