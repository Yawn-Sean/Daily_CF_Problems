/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=100010;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    std::vector<std::vector<int>> b(31);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        for(int j=0;j<31;j++) if(a[i]>>j&1) b[j].pb(a[i]);
    }
    int ans=-1;
    std::vector<int> res;
    for(int i=0;i<31;i++){
        int k=(1ll<<31)-1;
        if(b[i].empty()) continue;
        for(auto x:b[i]) k&=x;
        int v=(k&-k);
        if(v>ans) ans=v,res.swap(b[i]);
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
