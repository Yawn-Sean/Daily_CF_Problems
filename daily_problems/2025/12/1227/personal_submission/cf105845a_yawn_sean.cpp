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

	int n, mod = 1e9 + 7;
	cin >> n;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> f(n + 1), g(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;
	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	sort(nums.begin(), nums.end());
	vector<int> cnt(n, 0);

	for (auto &x: nums)
		cnt[lower_bound(nums.begin(), nums.end(), x) - nums.begin()] ++;

	int revn = 1ll * f[n - 1] * g[n] % mod;

	int last_k = 0, last_b = 0;
	int k = 0, b = 0;
	long long cur = -1;
	int resid = n;

	for (int i = n - 1; i >= 0; i --) {
		if (cnt[i]) {
			if (cur == -1)
				last_k = 1, last_b = 0;
			else {
				int rev_resid = 1ll * f[resid - 1] * g[resid] % mod;
				int vk = 1ll * n * rev_resid % mod;
				int rev_vk_1 = quickPow(vk - 1, mod - 2, mod);
				int pw_vk = quickPow(vk, cur - nums[i], mod);

				int vb, fix;
				vb = 1ll * (mod - k) * rev_resid % mod;
				fix = 1ll * (mod - vb) * rev_vk_1 % mod;
				last_k = (1ll * (last_k - fix + mod) % mod * pw_vk % mod + fix) % mod;

				vb = 1ll * (mod - (n + b) % mod) * rev_resid % mod;
				fix = 1ll * (mod - vb) * rev_vk_1 % mod;
				last_b = (1ll * (last_b - fix + mod) % mod * pw_vk % mod + fix) % mod;
			}
			k = (1ll * last_k * cnt[i] + k) % mod;
			b = (1ll * last_b * cnt[i] + b) % mod;
			cur = nums[i];
			resid -= cnt[i];
		}
	}

	cout << 1ll * (mod - last_b) * quickPow(last_k, mod - 2, mod) % mod;

	return 0;
}