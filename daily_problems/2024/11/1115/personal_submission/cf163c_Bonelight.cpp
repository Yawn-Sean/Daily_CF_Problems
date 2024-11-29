/*
    Bonelight * v *
    20241113：重 走 西 游
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
    int n,L,v1,v2; cin >> n >> L >> v1 >> v2;
    int d = L * v2;
    L *= (v1+v2);

    map<int,int> mp;
    mp[0] += 0, mp[2*L] += 0;

    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        x *= v1+v2;
        if(x + d <= L*2) {
            mp[x] ++;
            mp[x+d] --;
        } else {
            mp[0] ++;
            mp[L*2] --;
            mp[x] ++;
            mp[x + d - 2*L] --;
        }
    }
    
    vector<int> ans(n + 1);
    int last = 0, cnt = 0;
    for(auto [o,v]:mp){
        ans[cnt] += o - last;
        cnt += v;
        last = o;
    }

    cout << fixed << setprecision(20);
    for(auto x:ans){
        cout << 1.0 * x / (2*L) << endl;
    }
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
