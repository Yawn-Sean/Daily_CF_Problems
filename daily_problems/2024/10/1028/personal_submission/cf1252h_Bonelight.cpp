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
    int n; cin >> n;
    vector<pii> a(n);
    int ans = 0;
    for(int i = 0; i < n; i ++){
        int x,y; cin >> x >> y;
        if(x > y) swap(x,y);
        a[i] = {x,y};
        ans = max(ans, x * y);
    }
    sort(begin(a), end(a));
    
    int mx = 0;
    for(int i = n - 1; i >= 0; i --){
        auto &[x,y]=a[i];
        ans = max(ans, 2ll*x*min(y,mx));
        mx = max(mx,y);
    }
    cout << ans / 2 << '.' << (ans%2)*5 << endl;
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
