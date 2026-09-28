#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);

		long long v0 = 0, v1 = 0;

		for (int i = 0; i < n; i ++) {
			cin >> nums[i];
			if (i % 2 == 0) v0 += nums[i];
			else v1 += nums[i];
		}

		long long ans = -1e18;

		for (int i = 0; i < n; i ++) {
			v0 -= nums[i];
			swap(v0, v1);
			if (n % 2 == 0) v1 += nums[i];
			else v0 += nums[i];
			ans = max(ans, v0);
		}

		cout << ans << '\n';
	}

	return 0;
}