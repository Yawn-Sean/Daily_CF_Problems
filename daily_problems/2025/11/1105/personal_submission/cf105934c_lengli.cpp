/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    
    i64 res=inf;

    {
        i64 ans=0;
        int la=a[1];
        for(int i=2,flag=0;i<=n;i++,flag^=1){
            if(flag){
                if(a[i]>la){
                    la=a[i];
                    continue;
                }
                ans+=la-a[i]+1;
                la++;
            }else{
                if(a[i]<la){
                    la=a[i];
                    continue;
                }
                ans+=a[i]-la+1;
                la--;
            }
        }
        res=std::min(res,ans);
    }
    {
        i64 ans=0;
        int la=a[1];
        for(int i=2,flag=1;i<=n;i++,flag^=1){
            if(flag){
                if(a[i]>la){
                    la=a[i];
                    continue;
                }
                ans+=la-a[i]+1;
                la++;
            }else{
                if(a[i]<la){
                    la=a[i];
                    continue;
                }
                ans+=a[i]-la+1;
                la--;
            }
        }
        res=std::min(res,ans);
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
