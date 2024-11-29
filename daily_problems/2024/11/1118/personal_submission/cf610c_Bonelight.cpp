/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int k; cin >> k;
    if(k == 0) return void(cout << '+');
    vector<vector<int>> g((1 << k), vector<int>(1 << k));
    g[0][0] = 1, g[0][1] = 1, g[1][0] = 1, g[1][1] = 0;
    for(int i = 2; i <= k; i ++){
        int d = (1 << (i-1));
        for(int x = 0; x < d; x ++){
            for(int y = 0; y < d; y ++){
                g[x][y+d] = g[x][y];
                g[x+d][y] = !g[x][y];
                g[x+d][y+d] = g[x][y];
            }
        }
    }
    for(int i = 0 ; i < (1 << k); i ++){
        for(int j = 0; j < (1 << k); j ++){
            if(g[i][j] == 1) cout << "+";
            else cout << "*";
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
