/*
    Bonelight * v *
    20241002：国庆放假中
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n,a,b; cin >> n >> a >> b;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    if(a > 1 && b > 1) {cout << "NO" << endl; return;}
    if(a > 1 && b == 1){
        for(int i = 1; i <= n - a + 1; i ++){
            for(int j = 1; j <= n - a + 1; j ++){
                if(i != j) g[i][j] = 1;
            }
        }
    }
    if(a == 1 && b > 1){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i != j) g[i][j] = 1;
            }
        }
        for(int i = 1; i <= n - b + 1; i ++){
            for(int j = 1; j <= n - b + 1; j ++){
                if(i != j) g[i][j] = 0;
            }
        }
    }
    if(a == 1 && b == 1){
        if(n == 2 || n == 3){cout << "NO" << endl; return;}
        for(int i = 1; i <= n - 1; i ++){
            g[i][i + 1] = 1;
            g[i + 1][i] = 1;
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cout << g[i][j];
        }
        cout << endl;
    }
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
