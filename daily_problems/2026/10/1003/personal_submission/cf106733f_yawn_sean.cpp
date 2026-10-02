#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> max_full_cups(n);

	for (int i = 0; i < n; i ++) {
		nums[i] = min(nums[i], 1ll * k * (k + 1) / 2);

		int l = 1, r = k;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (1ll * (2 * k - mid + 1) * mid / 2 <= nums[i]) l = mid + 1;
			else r = mid - 1;
		}
		max_full_cups[i] = r;
	}

	int l = 1, r = k;

	while (l <= r) {
		int mid = (l + r) / 2, total = 0;

		for (int i = 0; i < n; i ++) {
			int x = max_full_cups[i];
			if (mid >= k + 1 - x) total += k - mid + 1;
			else {
				total += x;
				if (nums[i] - 1ll * (2 * k - x + 1) * x / 2 >= mid) total ++;
			}
			if (total >= m) break;
		}
		if (total >= m) l = mid + 1;
		else r = mid - 1;
	}

	long long ans = 0;
	int total = 0;

	for (int i = 0; i < n; i ++) {
		int x = max_full_cups[i];
		if (r >= k + 1 - x) {
			total += k - r + 1;
			ans += 1ll * (k + r) * (k - r + 1) / 2;
		}
		else {
			total += x;
			ans += 1ll * (2 * k - x + 1) * x / 2;

			if (nums[i] - 1ll * (2 * k - x + 1) * x / 2 >= r) {
				total ++;
				ans += nums[i] - 1ll * (2 * k - x + 1) * x / 2;
			}
		}
	}

	cout << ans + 1ll * (m - total) * r;

	return 0;
}