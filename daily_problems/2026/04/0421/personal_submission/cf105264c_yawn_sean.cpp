#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int t;
	cin >> t;

	long long inf = 1e13;

	while (t --) {
		int n;
		long long k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;
		sort(nums.begin(), nums.end());

		vector<long long> acc(n + 1, 0);
		for (int i = 0; i < n; i ++) acc[i + 1] = acc[i] + nums[i];

		vector<long long> dp(n + 1, inf);
		dp[0] = 0;

		for (int i = 1; i <= n; i ++) {
			vector<long long> ndp(n + 1, inf);
			
			for (int x = 0; x < n; x ++) {
				for (int y = x; y < n; y ++) {
					int mid = (x + y) / 2;
					long long cost = (acc[y + 1] - acc[mid] - 1ll * (y + 1 - mid) * nums[mid]) + (1ll * (mid - x) * nums[mid] - (acc[mid] - acc[x]));
					ndp[y + 1] = min(ndp[y + 1], dp[x] + cost);
				}
			}
			
			if (ndp[n] <= k) {cout << i << '\n'; break;}

			dp.swap(ndp);
		}
	}

	return 0;
}