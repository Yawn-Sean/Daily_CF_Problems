/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,k;
    std::cin>>n>>k;
    if(n<=1) std::cout<<1;
    else{
        int res=1;
        auto C=[&](int a,int b){
            int l=1,r=1;
            for(int i=0;i<b;i++) l*=a-i;
            for(int i=1;i<=b;i++) r*=i;
            return l/r;
        };
        auto F=[&](int x){
            int res=0;
            auto fac=[&](int v){
                int ans=1;
                for(int i=1;i<=v;i++) ans*=i;
                return ans;
            };
            int t=fac(x);
            for(int i=0,j=1;i<=x;i++,j*=-1){
                res+=t/fac(i)*j;
            }
            return res;
        };
        for(int i=2;i<=k;i++){
            res+=C(n,i)*F(i);
        }
        std::cout<<res;
    } 
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
