#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    vector<int> vis(1 << 22);
    for (auto &x : arr) {
        int bit = 32 - __builtin_clz(x);
        vis[((1 << bit) - 1) ^ x] |= 1 << (bit - 1);
    }

    int tot = (1 << 22) - 1;
    for (int j = tot; j >= 0; j--) {
        for (int bit = 0; bit < 22; bit++) {
            if (j >> bit & 1) {
                vis[j ^ (1 << bit)] |= vis[j];
            }
        }
    }

    vector<int> dp(tot + 1, 0);
    for (int i = 0; i <= tot; i++) {
        for (int bit = 0; bit < 22; bit++) {
            if (vis[i] >> bit & 1) {
                int ni = i | (1 << bit);
                dp[ni] = max(dp[ni], dp[i] + 1);
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}