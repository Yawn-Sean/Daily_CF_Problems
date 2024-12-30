/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> f(2,0);
    f[0]=0,f[1]=1023;
    for(int i=1;i<=n;i++){
        char op;
        int x;
        std::cin>>op>>x;
        if(op=='&') f[0]&=x,f[1]&=x;
        else if(op=='|') f[0]|=x,f[1]|=x;
        else f[0]^=x,f[1]^=x;
    }
    std::cout<<2<<"\n";
    std::cout<<"& "<<(f[0]^f[1])<<"\n";
    std::cout<<"^ "<<f[0]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
