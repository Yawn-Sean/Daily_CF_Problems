#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
		Iterate over the last ticket
	
        
    */
	int n;
    cin >> n;
    vector<int> nums(n + 1, -2000);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    vector<int> dp(n + 1, 0);
    int pt1 = 0, pt2 = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 20;

        while (nums[i] - nums[pt1] >= 90) { pt1++; }
        dp[i] = min(dp[i], dp[pt1 - 1] + 50);

        while (nums[i] - nums[pt2] >= 1440) { pt2++; }
        dp[i] = min(dp[i], dp[pt2 - 1] + 120);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i + 1] - dp[i] << endl;
    }
	return 0;
}
