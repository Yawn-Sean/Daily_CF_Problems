#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		long long k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		for (int i = 0; i < n; i ++) nums[i] -= i;

		multiset<int> left, right;
		long long total_left = 0, total_right = 0;

		int l = 0, r = -1, ans = 0;

		while (l < n) {
			while (r < n) {
				r ++;
				if (r == n) break;

				if (!left.empty() && *left.rbegin() < nums[r]) {
					right.insert(nums[r]);
					total_right += nums[r];
					while (left.size() < right.size()) {
						auto pt = *right.begin();
						right.erase(right.find(pt));
						total_right -= pt;
						left.insert(pt);
						total_left += pt;
					}
				}
				else {
					left.insert(nums[r]);
					total_left += nums[r];
					while (left.size() > right.size() + 1) {
						auto pt = *left.rbegin();
						left.erase(left.find(pt));
						total_left -= pt;
						right.insert(pt);
						total_right += pt;
					}
				}

				long long cur = total_right - total_left;
				if (left.size() > right.size()) cur += *left.rbegin();

				if (cur > k) break;
			}

			ans = max(ans, r - l);

			if (nums[l] <= *left.rbegin()) {
				left.erase(left.find(nums[l]));
				total_left -= nums[l];
				while (left.size() < right.size()) {
					auto pt = *right.begin();
					right.erase(right.find(pt));
					total_right -= pt;
					left.insert(pt);
					total_left += pt;
				}
			}
			else {
				right.erase(right.find(nums[l]));
				total_right -= nums[l];
				while (left.size() > right.size() + 1) {
					auto pt = *left.rbegin();
					left.erase(left.find(pt));
					total_left -= pt;
					right.insert(pt);
					total_right += pt;
				}
			}

			l ++;
		}
		cout << ans << '\n';
	}

	return 0;
}