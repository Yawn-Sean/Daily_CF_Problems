#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

vector<pair<ll,ll>>g[N];

il vector<ll> dijk(int n){
    vector<ll>dis(n+5,inf);
    vector<bool>vis(n+5);

    struct Node{
        ll id,ds;
        bool operator<(const Node&a)const{
            return ds>a.ds;
        }
    };
    priority_queue<Node>pq;
    pq.push({1,dis[1]=0});

    while(!pq.empty()){
        auto [u,d]=pq.top();
        pq.pop();

        if(vis[u])continue;
        vis[u]=true;

        for(auto [v,w]:g[u]){
            if(dis[u]+w<dis[v]){
                pq.push({v,dis[v]=dis[u]+w});
            }
        }
    }
    return dis;
}

ll fa[N];

il int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

il void me(int x,int y){
    fa[x]=find(x);
    
    fa[fa[x]]=find(y);
}

il void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    priority_queue<ll,vector<ll>,greater<ll>>pq;
    iota(fa,fa+n+3,0);
    
    struct Node{
        ll u,v,w;
    };
    vector<Node>p;
    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        p.push_back({u,v,w});
        me(u,v);
    }
    auto dis=dijk(n);
    ll ans=dis[n];

    ll sum=0;
    for(auto [u,v,w]:p){
        if(find(1)==find(u)){
            pq.push(w);
        }
    }
    while(k--&&!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    cout<<min(ans,sum);
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
