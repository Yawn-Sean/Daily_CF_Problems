/*
    Bonelight * v *
    20240930：放假的前一天，欧耶
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];
    
    vector<int> X(n + 1),sz(n + 1, 1);
    iota(begin(X),end(X), 0ll);
#pragma region 
    function<int(int)> find = [&](int o){return X[o] = X[o] == o? o:find(X[o]);};
    auto merge = [&](int xx, int yy){
        int x = find(xx), y = find(yy);
        if(x == y) return;
        X[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    };
#pragma endregion 

    for(int i = 0; i < n; i ++){
        merge(a[i],b[i]);
    }

    int ans = 0, cnt = n - 1;
    for(int i = 1; i <= n; i ++){
        if(find(i) == i){
            int d = sz[i] / 2;
            ans += 2 * (cnt * d + d * (d - 1) / 2 * (-2)); // 等差数列 公差 -2
            cnt -= d * 2;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
