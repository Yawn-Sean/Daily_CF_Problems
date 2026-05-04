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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

		int bound = n;
		vector<int> ans;

		for (int i = 2; i < n; i ++) {
			if (nums[order[i]] >= m) {
				if (nums[order[0]] + nums[order[1]] + nums[order[i]] <= 2 * m)
					ans = {order[0], order[1], order[i]};
				bound = i;
				break;
			}
		}
		
		if (ans.empty() && bound >= 3) {
			for (int i = 0; i <= 3; i ++) {
				vector<int> tmp;
				for (int j = 0; j < i; j ++) tmp.emplace_back(order[j]);
				for (int j = 0; j < 3 - i; j ++) tmp.emplace_back(order[bound - 1 - j]);

				int total = 0;
				for (auto &x: tmp) total += nums[x];

				if (total >= m && total <= 2 * m) {
					ans = tmp;
					break;
				}
			}
		}

		if (ans.empty()) cout << -1 << '\n';
		else cout << ans[0] + 1 << ' ' << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
	}

	return 0;
}