#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, x, k;
	cin >> n >> x >> k;
	
	vector<int> nums(n);
	for (auto& a: nums) { cin >> a; }
	
	sort(nums.begin(), nums.end());
	i64 ans = 0;
	for (int j = 0; j < n; j++) {
		i64 cur = nums[j];
		i64 cur_mod = nums[j] % x;

		i64 mn = cur - cur_mod - 1ll * k * x + 1;
		i64 mx = min(cur, mn + x - 1);
		// cout << mn << ' ' << mx << '\n';
		// >= mn
		auto it1 = lower_bound(nums.begin(), nums.end(), mn);
		int idx1 = it1 - nums.begin();
		// <= mx
		auto it2 = upper_bound(nums.begin(), nums.end(), mx);
		it2--;
		int idx2 = it2 - nums.begin();
		ans += (idx2 - idx1 + 1);
	}
	cout << ans << '\n';
	return 0;
}
