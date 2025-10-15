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
    if(m>=2*n){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<=m;j++){
            int v=(i+j)%(2*n);
            v/=2;v++;
            std::cout<<v<<" ";
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
