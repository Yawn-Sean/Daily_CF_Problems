/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,a,b;
    std::cin>>n>>a>>b;
    if(a>1 and b>1){
        std::cout<<"NO"<<"\n";
        return;
    }
    if(a==1 and b==1){
        if(n==1){
            std::cout<<"YES"<<"\n";
            std::cout<<0<<"\n";
            return;
        }
        if(n<=3){
            std::cout<<"NO"<<"\n";
            return;
        }
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(std::abs(i-j)==1) std::cout<<1;
                else std::cout<<0;
            }
            std::cout<<"\n";
        }
        return;
    }
    std::cout<<"YES"<<"\n";
    int cnt=(a==1 ? b : a);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) std::cout<<0;
            else if(i>=cnt and j>=cnt) std::cout<<(a>1 ? 1 : 0);
            else std::cout<<(a>1 ? 0 : 1);
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
