#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    const int B = 22;
    const int N = 1 << B;            
    static int vis[N]{};
    static int dp[N]{};

    for (int x : nums) {
        if (x == 0) continue;              
        int bit = 32 - __builtin_clz(x);  
        int v = (1 << bit) - 1;
        vis[v ^ x] |= (1 << (bit - 1));
    }

    for (int i = 0; i < B; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((j >> i) & 1) {
                vis[j ^ (1 << i)] |= vis[j];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < B; ++j) {
            if ((vis[i] >> j) & 1) {
                int ni = i | (1 << j);
                dp[ni] = max(dp[ni], dp[i] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}
