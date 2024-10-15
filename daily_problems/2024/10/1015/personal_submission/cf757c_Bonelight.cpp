/*
    Bonelight * v *
    20241015：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
#define int long long 
#define INF 5e14
#define pii pair<int,int>

void solve(){
    const int MO = 1e9 + 7;
    int n,m; cin >> n >> m;
    vector<vector<int>> g(m + 1, vector<int>());

    for(int i = 1; i <= n; i ++){
        int sz; cin >> sz;
        for(int j = 0; j < sz; j ++){
            int t; cin >> t;
            g[t].push_back(i);
        }
    }

    sort(begin(g) + 1, end(g));

    int len = 1;
    int ans = 1;
    for(int i = 1; i <= m - 1; i ++){
        if(g[i] == g[i + 1]) len ++;
        else len = 1; 
        ans = (ans * len) % MO;
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
