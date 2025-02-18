/*
    Bonelight * v *
    20241014：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>

void solve(){
    int n,m,b; cin >> n >> m >> b;
    vector<int> tv(n), cost(n), dp(1 << m, INF), q(n);
    dp[0] = 0;

    for(int i = 0; i < n; i ++){
        int x,y,z; cin >> x >> y >> z;
        cost[i] = x, tv[i] = y;
        for(int j = 0; j < z; j ++){
            int t; cin >> t; q[i] |= 1 << (t - 1);
        }  
    } 
    int ans = INF;
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx),end(idx), [&](int x, int y){
        return tv[x] < tv[y];
    });

    for(auto i:idx){
        for(int j = 0; j < (1 << m); j ++){
            dp[j | q[i]] = min(dp[j | q[i]], dp[j] + cost[i]);
        }
        ans = min(ans, dp[(1 << m) - 1] + tv[i] * b);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
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
