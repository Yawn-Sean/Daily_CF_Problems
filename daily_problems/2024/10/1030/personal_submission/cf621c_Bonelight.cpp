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
    int n,p; cin >> n >> p;
    vector<pii> a(n);
    for(auto &[x,y]:a) cin >> x >> y;
    
    auto check = [&](int xx, int yy) ->double{
        auto [x1,y1] = a[xx];
        auto [x2,y2] = a[yy];

        int d1 = y1 - x1 + 1;
        int d2 = y2 - x2 + 1;

        int t1 = y1 / p - (x1-1) / p;
        int t2 = y2 / p - (x2-1) / p;

        double res = t1 * d2 + t2 * d1 - t1 * t2;
        return res * 2000 / (d1*d2);
    };
    double ans = 0;
    for(int i = 0; i < n; i ++){
        // cout << check(i,(i+1)%n) << endl;
        ans += check(i,(i+1)%n);
    }
    cout << fixed << setprecision(18) << ans << endl;
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
