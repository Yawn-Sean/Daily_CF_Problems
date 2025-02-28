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
#define INF 2e18
#define pii pair<int,int>

void solve(){
    const double pi = acos(-1);
    int n,px,py; cin >> n >> px >> py;
    vector<pii> P(n);
    for(auto &[x,y]:P) cin >> x >> y;
    
    auto dist = [&](int x1, int y1, int x2, int y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
    };

    auto Td = [&](int x1, int y1, int x2, int y2) -> double{
        return 1.0 * abs((x2 - x1) * (py - y1) - (y2 - y1) * (px - x1));
    };

    int mx = -INF, tmi = INF;
    for(auto [x,y]:P){
        int d = dist(px,py,x,y);
        mx = max(mx, d);
        tmi = min(tmi, d);
    }

    double mi = tmi;
    for(int i = 0; i < n; i ++){
        auto [x1,y1] = P[i];
        auto [x2,y2] = P[(i + 1) % n];
        double area = Td(x1,y1,x2,y2);
        int ab = dist(x1,y1,x2,y2);
        int pa = dist(x1,y1,px,py);
        int pb = dist(px,py,x2,y2);
        if(!(ab + pa < pb) && !(ab + pb < pa)){
            mi = min(mi, area * area / dist(x1,y1,x2,y2));
        }
    }
    cout << fixed << setprecision(18) << pi * (mx - mi) << endl;
    // cout << mi << endl;
    // cout << mx << endl;
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
