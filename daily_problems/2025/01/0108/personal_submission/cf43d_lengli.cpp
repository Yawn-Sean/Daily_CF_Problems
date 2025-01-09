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
    int n,m;
    std::cin>>n>>m;
    if(n%2==0 and m>1){
        std::cout<<0<<"\n";
        for(int i=1;i<=n;i++){
            std::cout<<i<<" "<<1<<"\n";
        }
        for(int j=2;j<=m;j++){
            std::cout<<n<<" "<<j<<"\n";
        }
        for(int i=n-1,l=m,r=2,d=-1;i>=1;i--,std::swap(l,r),d*=-1){
            int t=l;
            while(1){
                std::cout<<i<<" "<<t<<"\n";
                if(t==r) break;
                t+=d;
            }
        }
        std::cout<<1<<" "<<1<<"\n";
    }else if(m%2==0 and n>1){
        std::cout<<0<<"\n";
        for(int i=1;i<=m;i++){
            std::cout<<1<<" "<<i<<"\n";
        }
        for(int i=2;i<=n;i++){
            std::cout<<i<<" "<<m<<"\n";
        }
        for(int j=m-1,l=n,r=2,d=-1;j>=1;j--,std::swap(l,r),d*=-1){
            int t=l;
            while(1){
                std::cout<<t<<" "<<j<<"\n";
                if(t==r) break;
                t+=d;
            }
        }
        std::cout<<1<<" "<<1<<"\n";
    }else{
        std::vector<std::array<int,2>> res;
        
        for(int i=1;i<=n;i++) res.pb({i,1});
        for(int j=2;j<=m;j++) res.pb({n,j});
        
        for(int i=n-1,l=m,r=2,d=-1;i>=1 and m>1;i--,std::swap(l,r),d*=-1){
            int t=l;
            while(1){
                res.pb({i,t});
                if(t==r) break;
                t+=d;
            }
        }
        auto [x,y]=res.back();
        if(std::abs(1-x)+std::abs(1-y)>1){
            std::cout<<1<<"\n";
            std::cout<<x<<" "<<y<<" "<<1<<" "<<1<<"\n";
        }else std::cout<<0<<"\n";
        res.pb({1,1});
        for(auto [x,y]:res) std::cout<<x<<" "<<y<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
