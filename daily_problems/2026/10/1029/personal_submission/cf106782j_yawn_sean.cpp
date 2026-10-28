#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	int cur = 0;
	long long ans = 0;

	for (int i = n - 1; i >= 0; i --) {
		if (nums[i] <= cur) cur -= nums[i];
		else {
			nums[i] -= cur;
			int w = (nums[i] + c - 1) / c;
			ans += 2ll * w * (i + 1);
			cur = w * c - nums[i];
		}
	}

	cout << ans;

	return 0;
}