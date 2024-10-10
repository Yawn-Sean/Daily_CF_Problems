/*
    Bonelight * v *
    20241010：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,k; cin >> n >> k;  
    vector<int> cnt_N(100005), cnt_F(100005), H(k+1);
    for(int i = 0; i < n * k; i ++){ int t; cin >> t; cnt_N[t] ++;}
    for(int i = 0; i < n; i ++){ int t; cin >> t; cnt_F[t] ++;}

    int ans = 0;
    for(int i = 1; i <= k; i ++) cin >> H[i];
    
    for(int i = 1; i <= 100000; i ++) if(cnt_F[i] && cnt_N[i]){
        // cout << cnt_N[i] << ' ' << cnt_F[i] << ' ';
        vector<int> dp(cnt_N[i] + 1);
        for(int j = 1; j <= cnt_F[i]; j ++){
            vector<int> ndp = dp;
            for(int v = k; v >= 0; v --){
                for(int p = cnt_N[i]; p - v >= 0; p --){
                    ndp[p] = max(ndp[p], dp[p - v] + H[v]);
                }
            }
            dp = ndp;
        }
        // cout << dp[cnt_N[i]] << endl;
        ans += dp[cnt_N[i]];
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
