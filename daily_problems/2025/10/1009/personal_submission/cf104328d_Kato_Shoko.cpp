#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e7 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

int n;
vector<int> a;
vector<vector<int>> g;
vector<int> pre;

pair<int,int> dfs_far(int u, int fa){
    pair<int,int> ans{0, u};
    pre[u] = fa;
    for(auto v : g[u]){
        if(v == fa) continue;
        auto t = dfs_far(v, u);
        if(t > ans) ans = t;
    }
    ans.first++;
    return ans;
}

void dfs_gcd(int u, int fa, int G, int d, map<int,int> &cur_mp){
    cur_mp[G] = max(cur_mp[G], d);
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs_gcd(v, u, std::gcd(G, a[v]), d + 1, cur_mp);
    }
}


il void solve(){
    cin>>n;
    a.assign(n,0);
    for(auto &i:a)cin>>i;
    g.assign(n,{});
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    pre.assign(n,-1);
    

    int s=dfs_far(0,-1).second;
    auto [d,mid]=dfs_far(s,-1);
    for(int i=0;i<d/2;i++){
        mid=pre[mid];
    }

    map<int,int>max_prefix;
    for(auto v:g[mid]){
        map<int,int>cur_mp;

        dfs_gcd(v,mid,gcd(a[mid],a[v]),1,cur_mp);

        for(auto [g,d]:cur_mp){
            if(g>1&&max_prefix[g]+d+1>n/2){
                cout<<"YES";
                return ;
            }
        }
        for(auto [gg,dd]:cur_mp){
            max_prefix[gg]=max(max_prefix[gg],dd);
        }
    }
    cout<<"NO";
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
