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

	int n;
	long long l;
	cin >> n >> l;

	vector<long long> nums(n + 1);
	nums[0] = 0, nums[n] = l;

	for (int i = 1; i <= n - 1; i ++)
		cin >> nums[i];

	int p1 = 0, p2 = 0;
	long long ans = l;

	for (int i = 2; i <= n - 2; i ++) {
		while (nums[p1 + 1] <= nums[i] - nums[p1 + 1]) p1 ++;
		while (nums[p2 + 1] - nums[i] <= l - nums[p2 + 1]) p2 ++;

		for (int d1 = p1; d1 <= p1 + 1; d1 ++) {
			for (int d2 = p2; d2 <= p2 + 1; d2 ++) {
				long long ma = max({nums[d1], nums[i] - nums[d1], nums[d2] - nums[i], l - nums[d2]});
				long long mi = min({nums[d1], nums[i] - nums[d1], nums[d2] - nums[i], l - nums[d2]});
				ans = min(ans, ma - mi);
			}
		}
	}

	cout << ans;

	return 0;
}