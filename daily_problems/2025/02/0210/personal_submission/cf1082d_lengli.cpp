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
    std::vector<int> a(n+2);

    std::vector<int> q,p,tmp;

    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(a[i]==1) q.pb(i);
        else p.pb(i);
    }
    tmp=p;
    int len=0;
    std::vector<std::array<int,2>> res;

    auto add=[&](int u,int v,int flag){
        if(!a[u] or !a[v]) return 0;
        a[u]--,a[v]--;
        res.pb({u,v});
        len+=flag;
        return 1;
    };

    if(p.empty()){
        std::cout<<"NO"<<"\n";
        return;
    }

    int s=p[0],t=p.back();
    while(p.size()!=1){
        auto t=p.back();
        p.pop_back();
        auto flag=add(t,p.back(),1);
        if(!flag){
            std::cout<<"NO"<<"\n";
            return;
        }
    }

    if(q.size()>=1){
        auto flag=add(s,q.back(),1);
        if(!flag){
            std::cout<<"NO"<<"\n";
            return;
        }
        q.pop_back();
    }
    if(q.size()>=1){
        auto flag=add(t,q.back(),1);
        if(!flag){
            std::cout<<"NO"<<"\n";
            return;
        }
        q.pop_back();
    }
    
    while(q.size()){
        sort(all(tmp),[&](auto l,auto r){
            return a[l]>a[r];
        });
        auto flag=add(tmp[0],q.back(),0);
        if(!flag){
            std::cout<<"NO"<<"\n";
            return;
        }   
        q.pop_back();
    }
    std::cout<<"YES"<<" "<<len<<"\n";
    std::cout<<res.size()<<"\n";
    for(auto [x,y]:res){
        std::cout<<x<<" "<<y<<"\n";
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
