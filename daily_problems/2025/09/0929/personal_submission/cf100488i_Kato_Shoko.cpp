#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e3 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

vector<int>g[N];
int colo[N];
bool vis[N];
bool adj[N][N];
vector<int>comp;

il void dfs(int u,int fa){
    vis[u]=true;
    comp.push_back(u);
    for(auto v:g[u]){
        if(!vis[v])dfs(v,fa);
    }
}

il void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==1){
        if(m){
            cout<<-1;
        }else{
            for(int i=1;i<=n;i++){
                cout<<1<<" ";
            }
        }
        return ;
    }


    while(m--){
        ll x,y;
        cin>>x>>y;
        adj[x][y]=adj[y][x]=true;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!adj[i][j]) g[i].push_back(j);
        }
    }

    vector<vector<int>>comps;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp.clear();
            dfs(i,i);
            comps.push_back(comp);
        }
    }

    for(auto &c:comps){
        int sz=(int)c.size();
        for(auto u:c){
            if((int)g[u].size()!=sz-1){
                cout<<-1;
                return;
            }
        }
    }

    if(comps.size()>k){
        cout<<-1;
        return;
    }

    for(int i=0;i<comps.size();++i){
        for(auto v:comps[i])colo[v]=i+1;
    }

    for(int i=1;i<=n;i++){
        cout<<colo[i]<<" ";
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
