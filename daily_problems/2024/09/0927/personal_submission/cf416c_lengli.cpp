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
    std::vector<std::array<int,3>> a(n);
    for(int i=0;i<n;i++){
        auto &[cnt,w,id]=a[i];
        std::cin>>cnt>>w;
        id=i;
    }
    sort(all(a),[&](auto l,auto r){
        if(l[1]!=r[1]) return l[1]>r[1];
        return l[0]<r[0];
    });
    int m;
    std::cin>>m;
    std::vector<std::array<int,2>> k(m);
    std::vector<int> st(m,0);
    for(int i=0;i<m;i++) {
        std::cin>>k[i][0];
        k[i][1]=i;
    }
    sort(all(k));
    std::vector<std::array<int,2>> res;
    int sum=0;
    for(auto [cnt,w,id]:a){
        for(int i=0;i<m;i++){
            auto [t,id1]=k[i];
            if(cnt<=t and !st[id1]){
                st[id1]=1;
                res.pb({id+1,id1+1});
                sum+=w;
                break;
            }
        }
    }
    std::cout<<res.size()<<" "<<sum<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
