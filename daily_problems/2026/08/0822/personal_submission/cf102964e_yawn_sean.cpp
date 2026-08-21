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

	int n, x, k;
	cin >> n >> x >> k;

	vector<int> nums(n);

	for (auto &v: nums) cin >> v;

	int mod = 1e9 + 7;

	if (k) {
		int total = (n - 1) * quickPow(2, k, mod) % mod;
		cout << ((x - 1) * quickPow(x, mod - 2, mod) % mod * total % mod + 1) % mod;
	}
	else {
		int ans = 1;
		for (int i = 1; i < n; i ++) ans += (nums[i] != nums[i - 1]);
		cout << ans;
	}

	return 0;
}