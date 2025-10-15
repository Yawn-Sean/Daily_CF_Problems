/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1912d 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)


void solve(){
    int n,m; cin >> n >> m;
    MATii g(n+1, VCii());
    
    int ok = 1;
    For(i,1,m) {
        int x,y,w; cin >> x >> y >> w;
        g[x].push_back({y,w});
        g[y].push_back({x,-w});
    }

    VC score(n+1, INF);
    function<void(int,int)> dfs = [&](int o, int fa){   
        for(auto [p,d]:g[o]){
            if(p == fa) continue;

            if(score[p] == INF) {
                score[p] = score[o] + d;
                dfs(p,o);
            } else if(score[p] != score[o] + d){
                ok = 0;
            }
        }
    };

    
    For(i,1,n){
        if(score[i] == INF){
            score[i] = 0;
            dfs(i,0);
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; cin >> T;
    while(T --) solve();
    return 0;
}
