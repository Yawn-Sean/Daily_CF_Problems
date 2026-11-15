#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> e(n+1);
    for(int i = 1;i < n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    int m;
    cin >> m;
    vector<int> deg(n+1,0);
    for(int i = 1;i <= m;i++){
        int u,v;
        cin >> u >> v;
        deg[u] ++,deg[v] ++;
    }
    ll ans = 0;
    auto dfs = [&](auto &&self,int u,int fa) -> int {
        int p = deg[u] & 1;
        for(auto [v,w] : e[u]){
            if(v == fa) continue;
            int take = self(self,v,u);
            if(take){
                ans += w;
                p ^= 1;
            }
        }
        return p;
    };
    dfs(dfs,1,0);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
