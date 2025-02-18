/*
    Bonelight * v *
    20241010：CF,Goodnight
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
    vector<int> X(n + 1), sz(n + 1,1);
    iota(begin(X), end(X), 0ll);
    int one = 0;
    vector<int> a(n + 1); 
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        one += x;
    }


    function<int(int)> find = [&](int o){ return X[o] = X[o] == o? o:find(X[o]);};
    auto merge = [&](int xx, int yy){
        int x = find(xx), y = find(yy);
        if(x == y) return;
        X[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    };
    for(int i = 1; i <= n; i ++){
        merge(i, a[i]);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(find(i) == i) ans ++;
    }
    if(ans == 1) ans = 0;
    if(one == 0 || (one % 2 == 0)) ans ++;
    cout << ans << endl;    
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
