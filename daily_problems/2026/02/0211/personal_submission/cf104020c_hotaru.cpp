#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define rep(i,a,b) for(int i = a ; i <= b ; i++)
using namespace std;
typedef long double ld;
void solve() {
    int c,t,r;
    cin >> c >> t >> r;
    ld p;
    cin >> p;
    vector<ld> times(c+1),dp(c+1,1e18);
    rep(i,1,c) {
        times[i] = (times[i-1] + 1 + p * r) / (1 - p);
    }
    dp[0] = 0;
    rep(i,1,c) {
        rep(j,1,i) {
            dp[i] = min(dp[i],dp[i-j] + times[j] + t);
        }
    }
    cout << fixed << setprecision(15);
    cout << dp[c] << endl;
}
signed main() {
    IOS;
    solve();
    return 0;
}