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
	for (auto& x: nums) { cin >> x; }
	
	int k = (n + 1) / 2;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cost[i] += max(nums[i - 1] - nums[i] + 1, 0);
		}
		if (i + 1 < n) {
			cost[i] += max(nums[i + 1] - nums[i] + 1, 0);
		}
	}
	
	vector<int> dp = cost;
	vector<int> preM(n);
	
	cout << *min_element(dp.begin(), dp.end()) << ' ';
	
	for (int i = 1; i < k; i++) {
		preM[0] = dp[0]; // 前缀最小值 dp[j][cnt-1] -> dp[i][cnt] 
		for (int j = 1; j < n; j++) {
			preM[j] = min(preM[j - 1], dp[j]);
		}
		
		for (int j = n - 1; j >= 2; j--) {
			// j < i - 2
			dp[j] = min(preM[j - 2] + cost[j], dp[j - 2] + cost[j] - max(nums[j - 1] - max(nums[j], nums[j - 2]) + 1, 0));
		}
		
		dp[0] = inf;
		dp[1] = inf;
		cout << *min_element(dp.begin(), dp.end()) << ' ';
	}

	
	return 0;
}
