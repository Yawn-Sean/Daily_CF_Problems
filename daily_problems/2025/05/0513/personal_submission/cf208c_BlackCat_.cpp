#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector e(n,std::vector<int>());
    for(int i=0;i<m;i++){
        int u,v;std::cin>>u>>v;
        u--;
        v--;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    std::vector<i64> cnt(n),cnt1(n);
    std::vector<i64> l(n,-1),l1(n,-1);
    std::queue<int> q;
    q.push(0);
    l[0]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:e[u]){
            if(l[v]==-1){
                l[v]=l[u]+1;
                q.push(v);
            }
        }
    }
    q.push(n-1);
    l1[n-1]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:e[u]){
            if(l1[v]==-1){
                l1[v]=l1[u]+1;
                q.push(v);
            }
        }
    }
    cnt[0]=1;
    q.push(0);
    std::vector<int> vis(n,0);
    while(!q.empty()){
        int u=q.front();

        q.pop();
        if(vis[u]==1){
            continue;
        }
        vis[u]=1;
        for(auto v:e[u]){
            if(l[v]==l[u]+1){
                cnt[v]+=cnt[u];
                q.push(v);
            }
        }
    }
    cnt1[n-1]=1;
    q.push(n-1);
    vis.assign(n,0);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u]==1){
            continue;
        }
        vis[u]=1;
        for(auto v:e[u]){
            if(l1[v]==l1[u]+1){
                cnt1[v]+=cnt1[u];
                q.push(v);
            }
        }
    }
    i64 ans=cnt[n-1];
    for(int i=1;i<n-1;i++){
        if(l[i]+l1[i]==l[n-1]){
            ans=std::max(ans,2*cnt[i]*cnt1[i]);
        }
    }
    std::cout<<std::fixed<<std::setprecision(12)<<(ld64)ans/cnt[n-1]<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
