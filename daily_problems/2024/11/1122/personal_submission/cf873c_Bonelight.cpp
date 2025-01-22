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
#define VC vector<int>
#define MAT vector<VC>

void solve(){   
    int n,m,k; cin >> n >> m >> k;
    k = min(k,n);
    MAT g(n+1,VC(m+1));
    for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= m; j ++){
        cin >> g[i][j];
    }

    for(int i = 1; i <= n; i ++)
    for(int j = 1; j <= m; j ++){
        g[i][j] += g[i - 1][j];
    }

    int score = 0, cnt = 0;
    for(int i = 1; i <= m; i ++){
        int c = 0, out = 0;
        for(int j = k; j <= n; j ++){
            if(g[j][i] - g[j-k][i] > c){
                c = g[j][i] - g[j-k][i];
                out = g[j-k][i];
            }
        }
        cnt += out;
        score += c;
    }

    cout << score << ' ' << cnt << endl;
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
