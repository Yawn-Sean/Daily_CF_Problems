#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long l, r, k;
	cin >> n >> l >> r >> k;

	vector<long long> nums(n);
	for (auto &v: nums) cin >> v;

	if (*min_element(nums.begin(), nums.end()) <= k || r < k)
		cout << -1;
	else {
		long long ans = 1;
		__int128_t bound = 1e12;

		for (auto &x: nums)
			ans = min((__int128_t)x * ans / gcd(x, ans), bound);

		ans = (r - k) / ans * ans + k;
		cout << (ans >= l && ans <= r ? ans : -1);
	}

	return 0;
}