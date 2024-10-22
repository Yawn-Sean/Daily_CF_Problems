/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<"YES"<<"\n";
        std::cout<<"2 1"<<"\n";
        std::cout<<"1 2"<<"\n";
        return;
    }
    if(n%2==0){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::vector<std::array<int,2>> edge;
    int idx=1;

    auto merge=[&](std::vector<int> &q){
        for(int i=0;i<q.size();i++){
            for(int j=i+1;j<q.size();j++){
                edge.pb({q[i],q[j]});
            }
        }
    };
    
    auto get=[&]()->std::array<int,2>{
        int u=idx++,v=idx++;
        int l=idx++,r=idx++;
        edge.pb({u,v});
        std::vector<int> q;
        for(int i=1;i<n;i++){
            int t=idx++;
            q.pb(t);
            edge.pb({u,t});
            edge.pb({l,t});
        }
        merge(q);
        q.clear();
        for(int i=1;i<n;i++){
            int t=idx++;
            q.pb(t);
            edge.pb({v,t});
            edge.pb({r,t});
        }
        merge(q);
        int L=idx++,R=idx++;
        edge.pb({L,l});edge.pb({R,r});
        return {L,R};
    };

    std::vector<std::array<int,2>> pt;
    auto root=get();
    while(pt.size()<n-1) pt.pb(get());
    
    for(int i=0;i<2;i++){
        std::vector<int> q;
        int cnt=(n-1)/2;
        while(cnt--){
            auto [l,r]=pt.back();
            q.pb(l),q.pb(r);
            pt.pop_back();
        }
        q.pb(root[i]);
        merge(q);
    }
    int N=idx-1,M=edge.size();
    if(M>1000000 or N>1000000){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
    std::cout<<N<<" "<<M<<"\n";
    for(auto [l,r]:edge){
        std::cout<<l<<" "<<r<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
