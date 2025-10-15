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

    std::vector<int> x(n+2),y(n+2);
    int v;

    for(int i=0;i<n;i++){
        std::cin>>x[i]>>y[i]>>v;
    }

    auto print=[&](std::vector<int> q){
        for(int i=1;i<n;i++) std::cout<<"(";
        for(int i=0;i<n;i++){
            if(i>=1) std::cout<<"+";
            std::cout<<"("<<q[i]/2<<"*((1-abs((t-"<<i<<")))+abs((abs((t-"<<i<<"))-1))))";
            if(i>=1) std::cout<<")";
        }
        std::cout<<"\n";
    };

    print(x);
    print(y);

    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
