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

	int t;
	cin >> t;

	while (t --) {
		int n;
		long long m;
		cin >> n >> m;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;
		sort(nums.begin(), nums.end());

		int l = 1, r = 1e7;

		while (l <= r) {
			int mid = (l + r) / 2;
			int pt = 0;
			long long cnt = 0;

			for (int i = 0; i < n; i ++) {
				while (pt < n && nums[pt] - nums[i] < mid) pt ++;
				cnt += (n - pt) * 2;
			}

			if (cnt <= m) r = mid - 1;
			else l = mid + 1;
		}

		vector<long long> acc(n + 1, 0);
		for (int i = 0; i < n; i ++)
			acc[i + 1] = acc[i] + nums[i];
		
		{
			int bound = l, pt = 0;
			long long cnt = 0, ans = 0;

			for (int i = 0; i < n; i ++) {
				while (pt < n && nums[pt] - nums[i] < bound) pt ++;
				cnt += (n - pt) * 2;
				ans += (acc[n] - acc[pt] - (n - pt) * nums[i]) * 2;
			}

			ans += (m - cnt) * (bound - 1);

			cout << ans << '\n';
		}
	}

	return 0;
}