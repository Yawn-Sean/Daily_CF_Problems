/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]+=c;}
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }

    std::vector<BIT> tr(n+2);
    std::vector<int> dep(n+2),top(n+2),len(n+2);

    top[1]=1,dep[1]=1;tr[1]=BIT(n+5);

    auto dfs=[&](auto self,int u,int fa,int t)->int{
        dep[u]=dep[fa]+1;
        top[u]=t;
        int k=1;
        for(auto x:eg[u]){
            if(x==fa) continue;
            k+=self(self,x,u,t);
        }
        return len[u]=k;
    };

    for(auto x:eg[1]){
        dfs(dfs,x,1,x);
        tr[x]=BIT(len[x]+5);
    }
    
    while(m--){
        int op;
        std::cin>>op;
        if(op==1){
            int x;
            std::cin>>x;
            if(x==1) std::cout<<tr[1].sum(1)<<"\n";
            else std::cout<<tr[1].sum(dep[x])+tr[top[x]].sum(dep[x])<<"\n";
        }else{
            int x,c,k;
            std::cin>>x>>c>>k;
            if(x==1){
                tr[1].add(1,c);
                tr[1].add(k+2,-c);
            }else if(dep[x]-k>=2){
                tr[top[x]].add(dep[x]-k,c);
                int limit=std::min(len[top[x]]+2,dep[x]+k+1);
                tr[top[x]].add(limit,-c);
            }else{
                int limit=std::min(len[top[x]]+2,dep[x]+k+1);
                tr[top[x]].add(limit,-c);
                int len=k-(dep[x]-1);
                tr[1].add(1,c);
                tr[1].add(len+2,-c);
                tr[top[x]].add(len+2,c);
            }
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
