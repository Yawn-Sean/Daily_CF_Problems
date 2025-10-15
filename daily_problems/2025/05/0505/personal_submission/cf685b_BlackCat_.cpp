#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector son(n,std::vector<int>());
    std::vector<int> par(n);
    par[0]=-1;
    int x;
    for(int i=1;i<n;i++){
        std::cin>>x;
        x--;
        par[i]=x;
        son[x].push_back(i);
    }
    std::vector<int> sz(n,0);
    auto dfs=[&](this auto&& self ,int u)->int{
        sz[u]=1;
        for(auto v:son[u]){
            sz[u]+=self(v);
        }
        return sz[u];
    };
    dfs(0);
    std::vector<int> ans(n,0);
    auto dfs1=[&](this auto &&self ,int u)->void{
        int mv=-1;
        for(auto v:son[u]){
            self(v);
            if(mv==-1||sz[v]>sz[mv]){
                mv=v;
            }
        }
        if(mv==-1){
            ans[u]=u;
        }
        else{
            mv=ans[mv];
            while(sz[mv]*2<sz[u]){
                mv=par[mv];
            }
            ans[u]=mv;
        }
    };
    dfs1(0);
    while(q--){
        std::cin>>x;
        x--;
        std::cout<<ans[x]+1<<endl;
    }
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
