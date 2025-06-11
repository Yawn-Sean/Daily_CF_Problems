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
    vector<int> a(n*2);
    vector<int> mpB(1000010,-1);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0, x; i < m; i ++) cin >> x, mpB[x]=i;
    for(int i = 0; i < n; i ++) a[i+n] = a[i];

    int ans = 0;
    int l = 0, r = 0, cur=0;

    while(l < n){
        if(r < l){
            r = l, cur = 0;
        } else if(l > 0){
            int d = mpB[a[l]] - mpB[a[l-1]];
            if(d < 0) d += m;
            cur -= d;
        }

        if(mpB[a[l]] == -1) {l++; continue;}

        while(r < l + n -1){
            if(mpB[a[r+1]] == -1) break;
            int d = mpB[a[r+1]] - mpB[a[r]];
            if(d < 0) d += m;
            if(cur + d >= m) break;
            r ++, cur += d;
        }
        ans = max(ans, r - l + 1);
        l++;
    }
    cout << ans << endl;
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
