/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),mi(n+2,inf);
    std::vector<std::array<int,4>> qr(m);
    for(auto &[op,l,r,x]:qr){
        std::cin>>op>>l>>r>>x;
        if(op==1){
            for(int i=l;i<=r;i++) a[i]+=x;
        }else{
            for(int i=l;i<=r;i++) mi[i]=std::min(mi[i],x-a[i]);
        }
    }

    std::vector<int> b(n+2);
    for(auto [op,l,r,x]:qr){
        if(op==1){
            for(int i=l;i<=r;i++) b[i]+=x;
        }else{
            int res=-inf;
            for(int i=l;i<=r;i++) res=std::max(res,mi[i]+b[i]);
            if(res!=x){
                std::cout<<"NO"<<"\n";
                return;
            }
        }
    }
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++){
        std::cout<<std::min(mi[i],1000000000)<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
