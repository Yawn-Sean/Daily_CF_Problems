/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++) cin >> a[i];
    vector<pii> edge(m);
    for(int i = 0; i < m; i ++) cin >> edge[i].first >> edge[i].second;
    
    vector<int> idx(n); iota(begin(idx), end(idx), 0);
    sort(begin(idx),end(idx),[&](int x, int y){return a[x] < a[y];});
    vector<int> ans(n);
    for(int i = 0; i < n; i += 2) ans[idx[i]] = 1;
    for(auto i:ans) cout << i << ' ';
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
