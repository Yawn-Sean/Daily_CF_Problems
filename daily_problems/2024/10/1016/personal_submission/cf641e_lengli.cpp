/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
    int n;
    std::cin>>n;
    std::map<int,std::vector<std::array<int,3>>> q;
    for(int i=1;i<=n;i++){
        int op,t,x;
        std::cin>>op>>t>>x;
        q[x].pb({op,t,i});
    }
    std::vector<int> res(n+2,-1);
    for(auto [_,a]:q){
        std::vector<int> idx;
        for(auto [op,t,id]:a) idx.pb(t);
        sort(all(idx));
        auto find=[&](int x)->int{
            return lower_bound(all(idx),x)-idx.begin()+1;  
        };
        BIT tr(idx.size()+2);
        for(auto [op,t,id]:a){
            t=find(t);
            if(op==1) tr.add(t,1);
            else if(op==2) tr.add(t,-1);
            else res[id]=tr.sum(t);
        }
    }
    for(int i=1;i<=n;i++){
        if(res[i]!=-1) std::cout<<res[i]<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
