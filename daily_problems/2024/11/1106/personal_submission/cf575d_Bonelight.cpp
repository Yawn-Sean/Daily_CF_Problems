/*
    Bonelight * v *
    20241028：58要早八
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
    int n = 1000;
    cout << 2000 << endl;
    for(int i = 1; i <= n; i ++) cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    for(int i = n; i >= 1; i --) cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << endl;
    
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
