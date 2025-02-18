/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,3>> a(n+2); 
    for(int i=1;i<=n;i++){
        auto &[u,v,id]=a[i];
        std::cin>>u>>v;
        if(u<v) std::swap(u,v);
        id=i;
    }

    sort(a.begin()+1,a.begin()+n+1);
    std::set<std::array<int,2>> s;
    s.insert({inf,inf});

    int la=-1;
    std::vector<std::array<int,2>> q;

    std::vector<int> res(n+2,-1);

    for(int i=1;i<=n;i++){
        if(a[i][0]==la) q.pb({a[i][1],a[i][2]});
        else{
            for(auto x:q) s.insert(x);
            q.clear(),q.pb({a[i][1],a[i][2]});
        }
        auto it=s.lower_bound({a[i][1],0});
        it=prev(it);
        if(it==s.end() or (*it)[0]>=a[i][1]) res[a[i][2]]=-1;
        else res[a[i][2]]=(*it)[1];
        la=a[i][0];
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
