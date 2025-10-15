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

    int q;
    std::cin>>q;
    while(q--){
        int op;
        std::cin>>op;
        if(op==1){
            int x,v;
            std::cin>>x>>v;
            a[x]=v;
        }else{
            int x;
            std::cin>>x;
            if(n>=2010){
                if(x<=1005) std::cout<<n<<"\n";
                else std::cout<<1<<"\n";
            }else{
                int res=-1;
                for(int i=1;i<=n;i++){
                    int v=x-i;
                    if(std::abs(1ll*v*v*v)>=a[i]) res=i;
                }
                std::cout<<res<<"\n";
            }
        }
    }
} 

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
