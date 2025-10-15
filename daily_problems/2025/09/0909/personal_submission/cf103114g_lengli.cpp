/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n;
    std::cin>>n;

    auto query=[&](std::vector<int> &a){
        std::cout<<a.size()<<" ";
        for(auto x:a) std::cout<<x<<" ";
        std::cout<<std::endl;
        std::vector<int> res;
        for(auto x:a){
            int t;
            std::cin>>t;
            res.pb(t);
        }
        return res;
    };

    auto print=[&](std::vector<int> a){
        std::cout<<"!"<<" ";
        for(auto x:a) std::cout<<x<<" ";
        std::cout<<std::endl;
    };

    std::vector<std::vector<int>> qr(11),qans(11);

    auto query_init=[&](auto self,int l,int r,int dep)->void{
        if(l==r) return;
        int mid=(l+r)>>1;
        for(int i=l;i<=mid;i++) qr[dep].pb(i);
        self(self,l,mid,dep+1);
        self(self,mid+1,r,dep+1);
    };

    query_init(query_init,1,n,0);

    for(int i=0;i<10;i++) if(qr[i].size()) qans[i]=query(qr[i]);

    auto dfs=[&](auto self,int l,int r,std::set<int> s,int dep)->std::vector<int>{
        if(l==r){
            std::vector<int> res;
            res.pb(*s.begin());
            return res;
        }
        int mid=(l+r)>>1;
        std::set<int> sl;
        std::vector<int> tmp;
        for(int i=l;i<=mid;i++) tmp.pb(i);
        auto ql=qans[dep];
        for(auto x:ql){
            if(s.count(x)) sl.insert(x),s.erase(x);
        }
        auto res=self(self,l,mid,sl,dep+1);
        for(auto x:self(self,mid+1,r,s,dep+1)) res.pb(x);
        return res;
    };

    std::set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    print(dfs(dfs,1,n,s,0));
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
