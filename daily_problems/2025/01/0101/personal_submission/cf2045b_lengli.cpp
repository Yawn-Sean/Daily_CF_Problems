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
    i64 n,d,s;
    std::cin>>n>>d>>s;
    n/=s,d/=s;
    if(n<=d+1) std::cout<<n*s<<"\n";
    else{
        n=std::min(n,d*2);
        for(int i=2;i<=1000000;i++){
            if(n%i==0 and n-n/i<=d){
                std::cout<<n*s<<"\n";
                return;
            }
        }
        std::cout<<(n-1)*s<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
