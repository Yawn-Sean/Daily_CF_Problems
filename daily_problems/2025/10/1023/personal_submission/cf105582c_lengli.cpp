/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

void solve(){
    int n,mi,mx;
    std::cin>>n>>mi>>mx;
    std::vector<std::array<int,2>> q(n);
    for(auto &[v,cnt]:q) std::cin>>v>>cnt;

    auto check=[&](int k)->bool{
        std::vector<int> f(mx+2,0);
        f[0]=1;

        for(auto [v,cnt]:q){
            cnt/=k;
            std::vector<int> g(mx+2);
           
            for(int mod=0;mod<v;mod++){
                int limit=-1;
                for(int j=mod;j<=mx;j+=v){
                    if(f[j]) limit=j+cnt*v;
                    if(j<=limit) g[j]=1;
                }
            }
            f.swap(g);
        }

        for(int i=mi;i<=mx;i++){
            if(f[i]>0) return 1;
        }
        return 0;
    };

    int l=0,r=1000010;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    std::cout<<l<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
