#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> vals(n);
	int total = 0, val = n;
	for (int i = 0; i < n; i ++) {
		vals[i] = (nums[i] >= 0 ? 1 : -1);
		total += abs(nums[i]);
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return abs(nums[i]) > abs(nums[j]);});

	int ma_total = total, ma_val = val, chosen = -1;

	for (int i = 0; i < n; i ++) {
		total += 2 * abs(nums[order[i]]);
		val += 8;

		if (1ll * total * total * ma_val > 1ll * ma_total * ma_total * val) {
			ma_total = total;
			ma_val = val;
			chosen = i;
		}
	}

	for (int i = 0; i <= chosen; i ++) vals[order[i]] *= 3;

	for (auto &x: vals) cout << x << ' ';

	return 0;
}