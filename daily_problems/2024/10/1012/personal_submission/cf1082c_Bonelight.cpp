/*
    Bonelight * v *
    20241011：CF,Goodnight
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(m + 1, vector<int>());
    vector<int> now;
    map<pii,int> mp;
    for(int i = 0; i < n; i ++){
        int x,y; cin >> x >> y;
        g[x].push_back(y);
    }
    for(int i = 1; i <= m; i ++) if(g[i].size()) {
        sort(begin(g[i]),end(g[i]),greater<int>());
        if(g[i][0] > 0) now.push_back(i);
        for(int j = 0, pre = 0; j < g[i].size(); j ++){
            pre += g[i][j];
            if(pre <= 0) break;
            mp[{i,j + 1}] = pre;
        }
    }

    // for(auto &[x,y]:mp) cout << x.first << ' ' << x.second << ' ' << y << endl;

    int cur = 1, mx = 0;
    while(now.size()){
        vector<int> nnow;
        int sum = 0;
        for(auto &i:now){
            sum += mp[{i,cur}];
            if(mp.count({i,cur + 1})) nnow.push_back(i);
        }
        cur ++;
        mx = max(mx,sum);
        now = nnow;
    }
    cout << mx << endl;
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
