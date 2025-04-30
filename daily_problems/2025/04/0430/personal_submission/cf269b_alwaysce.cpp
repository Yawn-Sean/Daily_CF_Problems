#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		double x;
		cin >> nums[i] >> x;
	}
	
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] <= nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	cout << n - *max_element(dp.begin(), dp.end());
	return 0;
}
