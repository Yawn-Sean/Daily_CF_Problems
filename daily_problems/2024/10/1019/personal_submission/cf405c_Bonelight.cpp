/*
    Bonelight * v *
    20241019：CF,Goodnight
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
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(i == j) ans ^= g[i][j]; 
        }
    }

    int q; cin >> q;
    while(q --){
        int op; cin >> op;
        if(op == 3) cout << ans;
        else cin >> op, ans ^= 1;
    }
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
