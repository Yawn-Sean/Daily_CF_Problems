#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		long long ans = k;

		for (int i = 0; i < n; i ++) {
			long long cur = k, cur_idx = i;

			for (int j = 1; j <= n && cur_idx < n && cur >= 0; j ++) {
				cur += nums[cur_idx];
				ans = max(ans, cur);
				cur_idx += j;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}