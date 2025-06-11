#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> nums(m);
	for (int i = 0; i < m; i++) {
		cin >> nums[i];
	}
	
	// x 变成 y
	// 对于a[i]
	// 1. a[i-1] , a[i] ; a[i - 1] != x, a[i] != x
	// 2. 都是x
	// 3. x a[i] => y a[i]
	// diff = sum(abs(y - a[k]))
	// k为a[i] = x左侧的所有下标k a[k] != x
	// 而diff的最小值是在中位数的地方取到
	vector<i64> cnt(n + 1);
	vector<vector<int>> tmp(n + 1);
	
	i64 old = 0;
	
	for (int i = 1; i < m; i++) {
		int v = abs(nums[i] - nums[i - 1]);
		old += v;
		
		if (nums[i] != nums[i - 1]) {
			cnt[nums[i]] += v;
			cnt[nums[i - 1]] += v;
		
			tmp[nums[i]].push_back(nums[i - 1]);
			tmp[nums[i - 1]].push_back(nums[i]);
		}
	}
	
	i64 dif = 0;
	for (int i = 1; i <= n; i++) {
		if (tmp[i].size() > 0) {
			sort(tmp[i].begin(), tmp[i].end());
			
			int mid = tmp[i][tmp[i].size() / 2];
			i64 cur = 0;
			for (auto& x: tmp[i]) {
				cur += abs(x - mid); 
			}
			
			dif = max(dif, cnt[i] - cur);
		}
	}
	cout << old - dif << '\n';
    return 0;
}
