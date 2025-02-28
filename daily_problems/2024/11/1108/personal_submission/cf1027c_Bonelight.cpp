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

void solve(){
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i ++){
        int x; cin >> x; mp[x] ++;
    }
    vector<int> a;
    for(auto [x,y]:mp){
        if(y / 2 >= 2) a.push_back(x), a.push_back(x);
        else if(y / 2 == 1) a.push_back(x); 
    }
    long double ans = INF;
    int Ax = -1, Ay = -1;
    for(int i = 0; i < a.size() - 1; i ++){
        int x = a[i], y = a[i + 1];
        long double o = 1.0 * (x + y)*(x + y) / (x*y);
        if(o < ans) Ax = x, Ay = y, ans = o;
    }
    cout << Ax << ' ' << Ax << ' ' << Ay << ' ' << Ay << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
