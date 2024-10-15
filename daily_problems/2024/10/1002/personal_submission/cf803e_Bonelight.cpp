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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(2*k + 1,INF));
    dp[0][k] = 0;
    map<char,vector<int>> mp1{
        {'W', {1}},
        {'L', {-1}},
        {'D', {0}},
        {'?', {-1, 0, 1}},
    };

    for(int i = 0; i < n; i ++){
        for(auto d:mp1[s[i]]){
            for(int j = 1; j < 2 * k; j ++){
                if(dp[i][j] != INF) dp[i + 1][j + d] = d;
            }
        }
    }

    int st;
    if(dp[n][0] != INF) st = 0;
    else if(dp[n][k * 2] != INF) st = 2 * k;
    else {cout << "NO" << endl; return;}

    map<int,string> mp2{
        {1,"W"},
        {-1,"L"},
        {0,"D"},
    };

    string ans;
    for(int i = n; i >= 1; i --){
        ans += mp2[dp[i][st]];
        st -= dp[i][st];
    }
    reverse(begin(ans), end(ans));
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
