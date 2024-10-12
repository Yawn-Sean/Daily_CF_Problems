/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=100000;
#define int long long

void solve(){
    int a,b,h,w;
    int n;
    std::cin>>a>>b>>h>>w>>n;
    std::vector<int> fac(n);
    for(auto &x:fac) std::cin>>x;
    sort(all(fac),std::greater<>());

    int len=std::min(50ll,n);

    auto cal=[&](int aa,int bb,int x,int y)->int{
        std::vector<std::vector<long long>> f(len+2,std::vector<long long> (100010,0));
        f[0][x]=y;
        for(int i=0;i<len;i++){
            long long k=fac[i];
            for(int j=1;j<=100000;j++){
                if(!f[i][j]) continue;
                int r=std::min(1ll*j*k,inf);
                f[i+1][r]=std::max(f[i+1][r],f[i][j]);
                f[i+1][j]=std::max(f[i+1][j],std::min(f[i][j]*k,inf));
            }
        }
        for(int i=0;i<=len;i++){
            for(int j=aa;j<=100000;j++)
                if(f[i][j]>=bb) {
                    return i;
                }
        }
        return -1;
    };

    int res=cal(a,b,h,w),ans=cal(a,b,w,h);
    if(res==-1 and ans==-1) std::cout<<"-1"<<"\n";
    else if(res==-1) std::cout<<ans<<"\n";
    else if(ans==-1) std::cout<<res<<"\n";
    else std::cout<<std::min(res,ans)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
