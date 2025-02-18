/*
    Bonelight * v *
    20241026：Hello, AtCoder
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
    int x, y; cin >> x >> y;
    int mx1 = y, mx2 = y, ans = 0;
    
    while(mx1 < x){
        int nmx = mx1 + mx2 - 1;
        mx2 = mx1, mx1 = nmx;
        ans ++;
    }
    
    ans += 2;
    cout << ans << endl;
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
