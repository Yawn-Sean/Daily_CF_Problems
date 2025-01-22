/*
    Bonelight * v *
    20241101：重 走 西 游
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
    int n,m; cin >> n >> m;
    vector<int> ddl(n+1),ans;
    int cur = 0, ok = 1;

    for(int i = 1; i <= n; i ++) cin >> ddl[i];
    vector<vector<tiii>> g(n + 1, vector<tiii>());
    
    for(int i = 1; i <= m; i ++) {
        int e,t,p; cin >> e >> t >> p;
        g[e].emplace_back(t,p,i);
    }

    for(int i = 1; i <= n; i ++){
        int sz = g[i].size();
        vector<vector<pii>> pre(101, vector<pii>(sz + 1, {-1,-1}));
        vector<int> dp(101, INF);
        dp[0] = 0;

        for(int id = 0; id < sz; id ++){
            auto [v,w,pos] = g[i][id];
            for(int j = 100; j >= 0; j --){
                if(dp[j] < INF){
                    int nv = min(100ll, j + w);
                    if(dp[nv] > dp[j] + v){
                        dp[nv] = dp[j] + v;
                        pre[nv][id + 1] = {pos,j};
                    }
                }
            }
        }

        if(dp[100] > ddl[i] - cur){
            ok = 0;
            break;
        }
        cur += dp[100];

        int p = 100;
        for(int j = sz; j > 0; j --){
            if(pre[p][j].first != -1){
                ans.emplace_back(pre[p][j].first);
                p = pre[p][j].second;
            }
        }
    }
    
    if(ok){
        cout << ans.size() << endl;
        for(auto x:ans){
            cout << x << ' ';
        }
        cout << endl;
    } else cout << -1 << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1; cin >> T;
    while(T --){
        solve();
    }
}
