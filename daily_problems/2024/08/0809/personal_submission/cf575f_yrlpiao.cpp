#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

const int N = 5e4 + 10, inf = 0x3f3f3f3f'3f3f3f3f;

int dp[2][N * 2] {}, n, x;
vector<int> nums;
int s[N], t[N];

int dis(int x, int l, int r) {
    if (x >= l && x <= r) return 0;
    if (x < l) return l - x;
    return x - r;
}

signed main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> t[i];
        nums.push_back(s[i]);
        nums.push_back(t[i]);
    }
    nums.push_back(x);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int mx = nums.back();
    for (int i = 0; i < nums.size(); i++) {
        dp[1][i] = abs(x - nums[i]) + dis(nums[i], s[1], t[1]);
    }
    for (int i = 2; i <= n; i++) {
        int mn = inf;
        for (int j = 0; j < nums.size(); j++) {
            mn = min(mn, dp[i - 1 & 1][j] - nums[j]);
            dp[i & 1][j] = mn + nums[j] + dis(nums[j], s[i], t[i]);
        }
        mn = inf;
        for (int j = nums.size() - 1; j >= 0; j--) {
            mn = min(mn, dp[i - 1 & 1][j] - mx + nums[j]);
            dp[i & 1][j] = min(dp[i & 1][j], mn + mx - nums[j] + dis(nums[j], s[i], t[i]));
        }
    }
    int ans = inf;
    for (int i = 0; i < nums.size(); i++) {
        ans = min(ans, dp[n & 1][i]);
    }
    cout << ans;
}
