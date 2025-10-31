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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> nums(q);
	for (auto &v: nums) cin >> v;

	int mod = 1e9 + 7, rev2 = (mod + 1) / 2;

	int cur = 0;
	for (int i = q - 1; i >= 0; i --)
		cur = 1ll * (cur + nums[i]) * rev2 % mod;
	
	vector<int> ans(n + 1, 0);
	ans[1] = cur;

	for (int i = 0; i < q; i ++) {
		cur = (cur * 2 - nums[i]) % mod;
		if (cur < 0) cur += mod;
		ans[nums[i]] += 1ll * cur * rev2 % mod;
		if (ans[nums[i]] >= mod) ans[nums[i]] -= mod;
	}

	for (int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';

	return 0;
}