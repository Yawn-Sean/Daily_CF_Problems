#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n;
	cin >> n;
	
	vector<int> nums(n);
	for (auto& v: nums) { cin >> v; }
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	stable_sort(order.begin(), order.end(), [&](int i, int j) {
		return nums[i] > nums[j];
	});
	
	vector<int> xs;
	vector<vector<int>> queries(n);
	
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		int k, x;
		cin >> k >> x;
		queries[k - 1].push_back(i);
		xs.push_back(x);
	}
	
	vector<int> ans(q);
	Fenwick<int> f(n + 1);
	
	for (int i = 0; i < n; i++) {
		f.add(order[i], 1); 
		for (auto& q_id: queries[i]) {
			int target = xs[q_id];
						
			int left = 1, right = n + 2;
			while (left < right) {
				int mid = (left + right) / 2;
				if (f.sum(mid) < target) {
					left = mid + 1;
				} else {
					right = mid;
				}
			}
			// cout << left << ' ' << f.sum(left) << '\n';
			ans[q_id] = nums[left - 1];
		}
	}
	
	for (auto& v: ans) {
		cout << v << '\n';
	}
	return 0;
}
