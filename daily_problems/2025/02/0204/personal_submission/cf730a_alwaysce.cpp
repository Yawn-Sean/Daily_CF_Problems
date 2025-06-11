#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> nums(n);
	for (auto& x: nums) { cin >> x; }
	
	vector<string> ans;
	auto op = [&](vector<int> idxs) {
		for (auto&i: idxs) { nums[i] = max(nums[i] - 1, 0); }
		string res(n, '0');
		for (auto&i: idxs) { res[i] = '1'; }
		ans.emplace_back(res);
	};
	
	while (*min_element(nums.begin(), nums.end()) != *max_element(nums.begin(), nums.end())) {
		int v = *max_element(nums.begin(), nums.end());
		vector<int> idxs;
		for (int i = 0; i < n; i++) {
			if (nums[i] == v) {
				idxs.push_back(i);
			}
		}
		int c = idxs.size();
		if (c > 1) {
			if (c % 2 == 0) {
				for (int i = 0; i < c; i += 2) {
					op({idxs[i], idxs[i + 1]});
				}
			} else {
				op({idxs[0], idxs[1], idxs[2]});
				for (int i = 3; i < c; i += 2) {
					op({idxs[i], idxs[i + 1]});
				}
			}
		} else {
			int idx = -1;
			for (int i = 0; i < n; i++) {
				if (nums[i] != v && (idx == -1 || nums[i] > nums[idx])) {
					idx = i;
				}
			}
			// cout << idx << nums[idx] << v << '\n';
			op({idx, idxs[0]});
		}
	}
	cout << nums[0] << '\n';
	cout << ans.size() << '\n';
	for (auto& x: ans) { cout << x << '\n';}
	return 0;
}
