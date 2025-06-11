#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> nums(n);

	for (auto& x: nums) { cin >> x; }

	set<int> s;	
	s.insert(nums[0]);
	vector<int> ans;
	map<int,int> l, r;
	for (int i = 1; i < n; i++) {
		// > nums[i]最小的
		auto it = s.lower_bound(nums[i]);
		if (it != s.end() && l[*it] == 0) {
			ans.push_back(*it);
			l[*it] = 1;
		} else {
			// < nums[i]最大的
			--it;
			ans.push_back(*it);
			r[*it] = 1;
		}
		s.insert(nums[i]);
	}
	
	for (auto&x: ans) { cout << x << ' '; }
	
	return 0;
}
