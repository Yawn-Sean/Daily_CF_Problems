#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> nums(3 * n);
	for (auto &x: nums) cin >> x;

	int l = 3 * n, r = 0;

	for (int i = 0; i < 3 * n; i ++) {
		if (nums[i] != i + 1) {
			l = min(l, i);
			r = max(r, i);
		}
	}

	if (l > r) return cout << 0, 0;

	if (r - l < 2 * n) {
		cout << 1 << '\n';
		cout << l + 1 << ' ' << r + 1 << '\n';
		return 0;
	}

	int ma_left = 0;

	for (int i = l; i < 3 * n; i ++) {
		if (nums[i] <= r - 2 * n + 1) {
			ma_left = max(ma_left, i);
		}
	}

	if (ma_left - l < 2 * n) {
		cout << 2 << '\n';
		cout << l + 1 << ' ' << ma_left + 1 << '\n';
		cout << r - 2 * n + 2 << ' ' << r + 1 << '\n';
		return 0;
	}

	int mi_right = 3 * n;

	for (int i = 0; i <= r; i ++) {
		if (nums[i] >= l + 2 * n + 1) {
			mi_right = min(mi_right, i);
		}
	}

	if (r - mi_right < 2 * n) {
		cout << 2 << '\n';
		cout << mi_right + 1 << ' ' << r + 1 << '\n';
		cout << l + 1 << ' ' << l + 2 * n << '\n';
		return 0;
	}

	cout << 3 << '\n';
	cout << 1 << ' ' << 2 * n << '\n';
	cout << n + 1 << ' ' << 3 * n << '\n';
	cout << 1 << ' ' << 2 * n << '\n';

	return 0;
}