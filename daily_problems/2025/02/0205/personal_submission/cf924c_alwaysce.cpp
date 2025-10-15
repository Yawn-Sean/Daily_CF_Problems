#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> nums(n);
	i64 ans = 0;
	for (auto&x: nums) { cin >> x; ans -= x; }
	
	/*
		a[i]+1 >= a[i+1]
		a[i+1] >= a[i] 成立
		
		水面以上标号的最小值
		
		题目给出的是严格高于水位的标记数量
		求严格低于水位分数的最小值
		
		等价于求整体的最小值
		nums = dp = 求整体不同种类标记的数量
	*/
	for (int i = n - 2; i >= 0; i--) {
		// 当天的标记数量至少是nums[i]
		// 由于下一天会多一个标记 所以至少是nums[i+1]-1 二者最大值
		nums[i] = max(nums[i], nums[i + 1] - 1);
	}
	
	for (int i = 1; i < n; i++) {
		// 前一天不增加 / 根据后缀影响求出的最大值
		nums[i] = max(nums[i - 1], nums[i]);
		ans += nums[i];
	}
	cout << ans;
	return 0;
}
