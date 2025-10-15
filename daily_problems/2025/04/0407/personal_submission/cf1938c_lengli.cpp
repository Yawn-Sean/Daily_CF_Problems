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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    i64 res=0;
    for(int i=2;i<=n;i++){
        int d=a[i]-a[i-1];
        if(d>1){
            std::cout<<"-1"<<"\n";
            return;
        }else if(d==1){
            if(res&1){
                std::cout<<"-1"<<"\n";
                return;
            }else res++;
        }else{
            d*=-1;
            if(res>>(d+1)&1){
                std::cout<<"-1"<<"\n";
                return;
            }
            for(int j=0;j<=d;j++){
                if(res<(1ll<<j)) res+=(1ll<<j);
                if(res>>j&1);
                else{
                    std::cout<<"-1"<<"\n";
                    return;
                }
            }
            res++;
        }
    }

    auto get=[&](i64 x){
        int c=0;
        for(int j=0;j<62;j++) if(x>>j&1) c++;
        return c;
    };

    int k=get(res);
    
    for(int j=0;j<62 and k<a[n];j++){
        if(res<(1ll<<j)) res+=(1ll<<j),k++;
    }
    res-=n,res++;
    
    for(i64 i=1,j=res;i<=n;i++,j++){
        k=get(j);
        if(k!=a[i]){
            std::cout<<"-1"<<"\n";
            return;
        }
    }
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
