/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=100010;

int n,k;
std::vector<int> eg[N];
std::vector<int> path;
int root=-1;

void dfs(int u,int fa,int len){
    if(root!=-1) return;
    if(len==k*2){
        root=path[k];
        return;
    }
    
    for(auto x:eg[u]){
        if(x==fa) continue;
        path.pb(x);
        dfs(x,u,len+1);
        path.pop_back();
    }
}

bool flag=1;

void check(int u,int fa,int len){
    if(len!=0 and len<k and eg[u].size()<4) flag=0;
    if(len==k and eg[u].size()!=1) flag=0;
    for(auto x:eg[u]){
        if(x==fa) continue;
        check(x,u,len+1);
    }
}

void solve(){
    std::cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }    
    for(int i=1;i<=n;i++){
        if(eg[i].size()==1){
            path.pb(i);
            dfs(i,-1,0);
            path.pop_back();
            break;
        }
    }
    if(root==-1 or eg[root].size()<3){
        std::cout<<"No"<<"\n";
        return;
    }

    check(root,-1,0);

    std::cout<<(flag ? "Yes" : "No")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
