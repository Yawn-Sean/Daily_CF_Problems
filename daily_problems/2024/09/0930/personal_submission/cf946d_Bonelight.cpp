/*
    Bonelight * v *
    20240930：放假的前一天，欧耶
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m,k; cin >> n >> m >> k;
    vector<int> dp(k + 1, 0);
    for(int i = 0; i < n; i ++){
        string s; cin >> s; 
        vector<int> idxs;
        for(int j = 0; j < m; j ++) if(s[j] == '1'){
            idxs.push_back(j);
        } 

        int len = idxs.size();
        vector<int> lv(len + 1, INF);
        lv[0] = 0;
        for(int d = 1; d <= len; d ++){
            for(int l = 0, r = l + d - 1; r < len; l ++, r ++){
                lv[d] = min(lv[d], idxs[r] - idxs[l] + 1);
            }
        }
        
        vector<int> ndp = dp;
        for(int j = k; j >= 0; j --){
            ndp[j] = dp[j] + lv[len];
            for(int d = 0; j - d >= 0 && len - d >= 0; d ++){
                ndp[j] = min(ndp[j], dp[j - d] + lv[len - d]);
            }
        }
        // for(int j = 0; j <= k; j ++) cout << dp[j] << ' '; cout << endl;
        dp = ndp;
    }
    cout << dp[k] << endl;
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
