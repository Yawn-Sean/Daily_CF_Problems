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
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		vector<array<pair<int, int>, 2>> pref(n + 1), suff(n + 1);
		pair<int, int> top1, top2;
		map<int, int> cnt;

		top1 = {0, 0}, top2 = {1, 0};
		pref[0] = {top1, top2};

		for (int i = 0; i < n; i ++) {
			cnt[nums[i]] ++;
			int cur_freq = cnt[nums[i]];

			if (nums[i] == top1.first)
				top1 = {nums[i], cur_freq};
			else if (cur_freq > top1.second) {
				top2 = top1;
				top1 = {nums[i], cur_freq};
			}
			else if (nums[i] == top2.first || cur_freq > top2.second)
				top2 = {nums[i], cur_freq};
			
			pref[i + 1] = {top1, top2};
		}

		cnt.clear();

		top1 = {0, 0}, top2 = {1, 0};
		suff[n] = {top1, top2};

		for (int i = n - 1; i >= 0; i --) {
			cnt[nums[i]] ++;
			int cur_freq = cnt[nums[i]];

			if (nums[i] == top1.first)
				top1 = {nums[i], cur_freq};
			else if (cur_freq > top1.second) {
				top2 = top1;
				top1 = {nums[i], cur_freq};
			}
			else if (nums[i] == top2.first || cur_freq > top2.second)
				top2 = {nums[i], cur_freq};
			
			suff[i] = {top1, top2};
		}

		int ans = 0;
		for (int i = 0; i <= n; i ++) {
			for (auto &[x1, y1]: pref[i]) {
				for (auto &[x2, y2]: suff[i]) {
					if (y1 && y2 && x1 != x2) {
						ans = max(ans, y1 + y2);
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}