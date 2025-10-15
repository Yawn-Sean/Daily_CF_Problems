/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define i128 __int128

#define int long long

i64 mod=(1ll<<32);

constexpr i64 inf=8e18;

void solve(){
    i64 n,l,r,x,y,z;
    std::cin>>n>>l>>r>>x>>y>>z;
    std::vector<i64> b(n+2);
    std::vector<i64> a(n+2);
    std::cin>>b[1]>>b[2];
    for(int i=3;i<=n;i++) {
        b[i]=((i128)b[i-2]*x+(i128)b[i-1]*y+z)%mod;
    }
    for(int i=1;i<=n;i++) a[i]=b[i]%(r-l+1)+l;


        i64 res=inf;
    
    {
        std::array<i64,2> f={inf,inf};
 
        auto insert=[&](i64 x){
            if(x<f[0]) f[1]=f[0],f[0]=x;
            else if(x<f[1]) f[1]=x;
        };
 
        for(int i=1;i<=n;i++){
            if(a[i]>=0){
                if(f[0]<a[i]) res=std::min(res,f[0]*a[i]);
                if(f[1]<a[i]) res=std::min(res,f[1]*a[i]);
            }
            insert(a[i]);
        }
    }
    {
        std::array<i64,2> f={-inf,-inf};
 
        auto insert=[&](int x){
            if(x>f[0]) f[1]=f[0],f[0]=x;
            else if(x>f[1]) f[1]=x;
        };
 
        for(int i=n;i>=1;i--){
            if(a[i]<=0){
                if(f[0]>a[i]) res=std::min(res,f[0]*a[i]);
                if(f[1]>a[i]) res=std::min(res,f[1]*a[i]);
            }
            insert(a[i]);
        }
    }
    if(res==inf) std::cout<<"IMPOSSIBLE"<<"\n";
    else std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
