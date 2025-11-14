#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;



void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n + 5);
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    vector<vector<int>> dp(k + 5, vector<int>(1e4 + 5));
    dp[0][0] = 1;
    sort(nums.begin() + 1, nums.begin() + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = nums[i] + 1; j <= 1e4 + 1; j++) {
            ans += dp[k - 1][j];
            ans %= mod;
        }
        for (int j = 1e4 + 1; j >= 0; j--) {
            for (int x = k - 2; x >= 0; x--) {
                if (j + nums[i] > 1e4 + 1) {
                    dp[x + 1][1e4 + 1] += dp[x][j];
                    dp[x + 1][1e4 + 1] %= mod;
                }
                else {
                    dp[x + 1][j + nums[i]] += dp[x][j];
                    dp[x + 1][j + nums[i]] %= mod;
                }
            }
        }
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}