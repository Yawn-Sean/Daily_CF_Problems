#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector e(n,std::vector<std::pair<int,int>>());
    int u,v,w;
    for(int i=0;i<m;i++){
        std::cin>>u>>v>>w;
        u--;
        v--;
        e[u].push_back(std::make_pair(v,w));
        e[v].push_back(std::make_pair(u,w));
    }
    std::vector<int> p(n);
    for(int i=0;i<n;i++){
        std::cin>>p[i];
    }
    std::priority_queue<std::tuple<i64,int,int>,std::vector<std::tuple<i64,int,int>>,std::greater<>> q;
    q.push({0,0,0});
    std::vector<std::vector<int>> vis(n,std::vector<int>(n,0));
    std::vector<int> k(n,1e9);

    while(!q.empty()){
        auto [x,y,z]=q.top();
        q.pop();
        if(y==n-1){
            std::cout<<x<<endl;
            return ;
        }
        if(vis[y][z]){
            continue;
        }
        vis[y][z]=1;
        k[y]=std::min(k[y],z);
        for(auto [v,w]:e[y]){
            int nz=z;
            if(p[v]<p[z]){
                nz=v;
            }
            if(!vis[v][nz]){
                q.push({x+1ll*p[z]*w,v,nz});
            }
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
