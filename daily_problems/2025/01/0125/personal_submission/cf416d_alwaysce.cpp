#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	
	/*
		-1 x ... y
		
		y x 两个非-1元素要么在同一个等差数列内部
		要么作为两个part
		
		[...x]  [y...]
		或者 [... x ... y]
		
		前一段尽可能长的贪心是否正确?
	*/
	
	vector<int> nums(n);
	for (auto& x: nums) { cin >> x; }
	
	int l = -1, r = -1, ans = 1;
	int start = 0;
	
	for (int i = 0; i < n; i++) {
		if (nums[i] == -1) {
			if (r != -1) {
				i64 v = 1ll * (nums[r] - nums[l]) / (r - l) * (i - l) + nums[l];
				if (v <= 0) {
					ans++;
					start = i;
					l = -1, r = -1;
				}
			}
		} else {
			if (l == -1) { l = i; }
			else if (r == -1) {
				if ( ((nums[i] - nums[l]) % (i - l) != 0) or (1ll * (nums[i] - nums[l]) / (i - l) * (start - l) + nums[l] <= 0)) {
					ans++;
					start = i, l = i, r = -1;
				} else {
					r = i;
				}
			} else {
				i64 v = 1ll * (nums[r] - nums[l]) / (r - l) * (i - l) + nums[l];
				// cout << l << ' ' << r << ' ' << v << '\n';
				if (nums[i] != v) {
					ans++;
					start = i, l = i, r = -1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
