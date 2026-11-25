#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < n - 1; j ++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
				cout << 'S';
			}
			cout << 'P';
		}
		cout << 'P';
	}

	return 0;
}