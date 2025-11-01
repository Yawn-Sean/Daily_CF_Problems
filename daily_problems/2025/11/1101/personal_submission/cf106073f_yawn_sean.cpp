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
	vector<int> ans(n + 1, 0);

	int cur = 0;
	reverse(nums.begin(), nums.end());

	for (auto &v: nums) {
		ans[v] = (1ll * cur * rev2 + ans[v]) % mod;
		cur = 1ll * (cur + v) * rev2 % mod;
	}

	ans[1] = (ans[1] + cur) % mod;

	for (int i = 1; i <= n; i ++)
		cout << ans[i] << '\n';

	return 0;
}