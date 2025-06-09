#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int mex = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] == mex) mex++;
    }
    
    vector<int> dp(n + 1, INT_MAX);
    vector<int> cnt(n + 1);
    for (auto i : a) {
        if (i < n) cnt[i]++;
    }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i] = min(dp[i], dp[j] + cnt[i] * j);
        }
    }
    cout << dp[0] - mex << endl;

}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}
