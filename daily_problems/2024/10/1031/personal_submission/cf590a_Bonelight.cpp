/*
    Bonelight * v *
    20241031：重 走 西 游 路
    登 神 长 阶， 灯 升 长 阶
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
    vector<int> a(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    int st = 0, ans = 0;

    for(int i = 0; i < n - 1; i ++){
        if(a[i] == a[i + 1]){
            ans = max(ans, (i - st) / 2);
            for(int l = st, r = i; l <= r; l ++, r --){
                a[l] = a[st], a[r] = a[i];
            }
            st = i + 1;
        }
    }
    ans = max(ans,(n - st - 1) / 2);
    for(int l = st, r = n - 1; l <= r; l ++, r --){
        a[l] = a[st], a[r] = a[n - 1];
    }

    cout << ans << endl;
    for(auto i:a) cout << i << ' ';
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
