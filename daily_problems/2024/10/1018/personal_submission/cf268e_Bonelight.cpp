/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[x,y]:a) cin >> x >> y;
    sort(begin(a),end(a), [&](auto &x, auto &y){
        auto [a1,b1] = x;
        auto [a2,b2] = y;
        return (100 - b2) * a1 * b1 > (100 - b1) * a2 * b2;
    });
    double ans = 0;  
    double pre = 0;
    for(int i = 0; i < n; i ++){
        auto [x,y] = a[i];
        ans += x + (double)(100 - y) / 100 * pre;
        pre += (double)y / 100 * x;
    }
    cout << fixed << setprecision(10) << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
