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
    int n; cin >> n;
    vector<int> a(n);
    int ans = 0, tot = 0;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        tot += a[i];
    }
    string s; cin >> s;
    for(int i = n-1; i >= 0; i --){
        tot -= a[i];
        if(s[i] == '1'){
            ans = max(tot,ans);
            tot += a[i];
        }
    }
    cout << max(ans,tot) << endl;
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
