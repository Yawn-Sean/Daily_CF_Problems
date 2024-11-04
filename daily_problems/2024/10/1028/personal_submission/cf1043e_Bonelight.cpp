/*
    Bonelight * v *
    20241023：CF,Goodnight
    登神长阶， 灯 升 长 阶
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,m; cin >> n >> m;
    int totx = 0, toty = 0;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i ++){
        auto &[x,y] = a[i]; cin >> x >> y;
        toty += y;
    }

    vector<int> idx(n + 1), ans(n + 1);
    iota(begin(idx), end(idx), 0ll);
    sort(begin(idx) + 1, end(idx), [&](int x, int y){
        return a[x].first + a[y].second < a[y].first + a[x].second;
    });

    for(int i = 1; i <= n; i ++){
        auto [x,y] = a[idx[i]];
        toty -= y;
        ans[idx[i]] = totx + toty + (i - 1) * y + (n - i) * x;
        totx += x; 
    }

    while(m --){
        int x, y; cin >> x >> y;
        int val = min(a[x].first + a[y].second, a[x].second + a[y].first);
        ans[x] -= val;
        ans[y] -= val;
    } 

    for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
