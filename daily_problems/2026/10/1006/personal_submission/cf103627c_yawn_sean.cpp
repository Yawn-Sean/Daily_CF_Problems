#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(1 << n);
	for (auto &x: nums) cin >> x;

	for (int i = 0; i < 1 << n; i ++) {
		vector<int> v1, v2;
		for (int j = 0; j < n; j ++) {
			if (i >> j & 1) v1.emplace_back(1 << j);
			else v2.emplace_back(1 << j);
		}

		for (auto &x1: v1) {
			for (auto &x2: v2) {
				if (nums[i - x1] + nums[i + x2] > nums[i] + nums[i - x1 + x2]) {
					cout << i << ' ' << i - x1 + x2 << '\n';
					return 0;
				}
			}
		}
	}

	cout << -1;

	return 0;
}