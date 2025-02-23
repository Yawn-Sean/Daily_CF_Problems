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
    int n,k,s,t;
    std::cin>>n>>k>>s>>t;
    std::vector<std::array<int,2>> pos(n);
    for(auto &[w,v]:pos) std::cin>>w>>v;
    sort(all(pos),[&](auto l,auto r){
        if(l[0]!=r[0]) return l[0]<r[0];
        return l[1]>r[1];
    });
    for(int i=1;i<n;i++) pos[i][1]=std::max(pos[i-1][1],pos[i][1]);
    std::vector<int> idx;
    idx.pb(0);
    for(int i=0;i<k;i++){
        int x;
        std::cin>>x;
        idx.pb(x);
    }
    idx.pb(s);
    sort(all(idx));

    int l=0,r=n-1;

    auto check=[&](int o)->bool{
        auto [w,v]=pos[o];
        int ans=0;
        for(int i=1;i<idx.size();i++){
            int len=idx[i]-idx[i-1];
            int x=2*len-v;
            if(x>len) return 0;
            if(x<0) x=0;
            ans+=len+x;
        }
        return ans<=t;
    };

    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(check(r)) std::cout<<pos[r][0]<<"\n";
    else std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
