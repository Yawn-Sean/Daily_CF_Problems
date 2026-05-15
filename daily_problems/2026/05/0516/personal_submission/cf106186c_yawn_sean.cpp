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

	int n, m;
	cin >> n >> m;

	vector<int> pr(m), nums(n);
	for (auto &x: pr) cin >> x;
	for (auto &x: nums) cin >> x;

	vector<int> cnt(1 << m, 0);

	for (auto &v: nums) {
		int msk = 0;
		for (int i = 0; i < m; i ++) {
			if (v % pr[i] == 0) {
				msk |= 1 << i;
			}
		}
		cnt[msk] ++;
	}

	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < 1 << m; j ++) {
			if (j >> i & 1) {
				cnt[j ^ (1 << i)] += cnt[j];
			}
		}
	}

	int mod = 1e9 + 7;
	for (int i = 0; i < (1 << m); i ++)
		cnt[i] = quickPow(2, cnt[i], mod) - 1;

	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < 1 << m; j ++) {
			if (j >> i & 1) {
				int nj = j ^ (1 << i);
				cnt[nj] = (cnt[nj] - cnt[j] + mod) % mod;
			}
		}
	}

	vector<int> vals(1 << m, 1);

	for (int i = 1; i < 1 << m; i ++)
		vals[i] = 1ll * vals[i - (i & -i)] * pr[__builtin_ctz(i)] % mod;

	int ans = 0;
	for (int i = 0; i < 1 << m; i ++)
		ans = (ans + 1ll * vals[i] * cnt[i]) % mod;

	cout << ans;

	return 0;
}