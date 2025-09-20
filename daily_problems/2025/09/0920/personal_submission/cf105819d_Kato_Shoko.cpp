#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0): n(n), p(n), sz(n,1) {
        for(int i=0;i<n;i++) p[i]=i;
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
    }
};

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;
    vector<pair<ll,ll>>g;
    for(int i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        u--;v--;
        g.push_back({u,v});
    }
    vector<string>ans(n,string(n,'0'));

    for(int c=0;c<30;c++){
        DSU dsu(n);
        vector<bool>has(n);
        for(int i=0;i<n;i++){
            if((a[i]>>c)&1)has[i]=1;
        }
        for(auto [u,v]:g){
            if(has[u]&&has[v])dsu.unite(u,v);
        }
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(has[i]){
                int r=dsu.find(i);
                mp[r].push_back(i);
            }
        }

        for(auto [x,vec]:mp){
            for(auto u:vec){
                for(auto v:vec){
                    ans[u][v]='1';
                }
            }
        }
    }
    for(auto s:ans)cout<<s<<'\n';
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
