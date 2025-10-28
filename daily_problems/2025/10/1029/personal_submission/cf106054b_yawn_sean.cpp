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

	int n, k, mod = 998244353;
	cin >> n >> k;

	vector<int> nums(n - k + 1), tmp(n, 0);
	for (auto &x: nums) cin >> x;

	for (int i = k; i < n; i ++)
		tmp[i] = tmp[i - k] + nums[i - k + 1] - nums[i - k];

	long long to_add = 0;
	for (int i = 0; i < k; i ++) {
		int val = 0;
		for (int j = i; j < n; j += k)
			val = min(val, tmp[j]);
		to_add -= val;
	}

	if (to_add > nums[0]) cout << 0;
	else {
		int tot = nums[0] - to_add, v1 = 1, v2 = 1;

		for (int i = 1; i < k; i ++) {
			v1 = 1ll * v1 * (tot + k - i) % mod;
			v2 = 1ll * v2 * i % mod;
		}

		cout << 1ll * v1 * quickPow(v2, mod - 2, mod) % mod;
	}

	return 0;
}