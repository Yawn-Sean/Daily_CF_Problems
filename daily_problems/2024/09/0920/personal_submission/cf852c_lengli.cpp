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
    std::vector<int> pt(n);
    for(auto &x:pt) std::cin>>x;

    std::vector<int> b(n); 
    for(int i=0;i<n;i++) b[i]=i;
    sort(all(b),[&](auto l,auto r){
        auto ll=pt[l]+pt[(l+1)%n];
        auto rr=pt[r]+pt[(r+1)%n];
        return ll<rr;
    });
    std::vector<int> res(n);
    for(int i=0;i<n;i++) res[b[i]]=i;
    for (auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
