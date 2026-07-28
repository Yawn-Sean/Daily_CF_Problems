#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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

	int k, mod = 1e9 + 7;
	cin >> k;

	vector<pair<int, int>> pts(k + 2);
	for (auto &[x, y]: pts) cin >> x >> y;

	vector<int> saved_vals(k + 2);

	for (int i = 0; i < k + 2; i ++) {
		int val = 1;
		for (int j = 0; j < k + 2; j ++) {
			if (i == j) continue;
			val = 1ll * val * (mod + pts[i].first - pts[j].first) % mod;
		}
		saved_vals[i] = pts[i].second * quickPow(val, mod - 2, mod) % mod;
	}

	for (int i = 0; i < k + 2; i ++) {
		int val = 0;
		for (int j = 0; j < k + 2; j ++) {
			if (i == j) continue;
			val += 1ll * saved_vals[j] * (mod + pts[i].first - pts[j].first) % mod;
			val %= mod;
		}
		if (val == 0) {
			int ans = 0;
			for (int j = 0; j < k + 2; j ++) {
				if (j != i) {
					int A = pts[j].second, B = 1;
					for (int v = 0; v < k + 2; v ++) {
						if (v != i && v != j) {
							A = 1ll * A * (mod - pts[v].first) % mod;
							B = 1ll * B * (mod + pts[j].first - pts[v].first) % mod;
						}
					}
					ans += A * quickPow(B, mod - 2, mod) % mod;
					ans %= mod;
				}
			}
			cout << ans << '\n';
			break;
		}
	}

	return 0;
}