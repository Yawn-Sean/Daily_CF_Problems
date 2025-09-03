#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void bfs(int n,vector<vector<int>>&g,vector<bool>&vis,vector<int>&f,int p){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(f[i]==p){
            vis[i]=true;
            q.push(i);
        }
    }
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v:g[u]){
            if(!vis[v]){
                if(p==1){
                    vis[v]=true;
                    q.push(v);
                }else{
                    vis[v]=true;
                    if(f[v]!=1)q.push(v);
                }
            }
        }
    }
}

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>f(n+1);
    for(int i=1;i<=n;i++)cin>>f[i];
    vector<vector<int>>g(n+1),rg(n+1);
    while(m--){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    vector<bool>vis(n+1,false),rvis(n+1,false);
    bfs(n,g,vis,f,1);
    bfs(n,rg,rvis,f,2);

    for(int i=1;i<=n;i++){
        if(vis[i]&&rvis[i])cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
