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
    auto query=[&](int idx,int val)->int{
        std::cout<<"? "<<idx<<" "<<val<<std::endl;
        char c;
        std::cin>>c;
        return c=='=' ? 0 : c=='<' ? -1 : 1;
    };
    auto print=[&](std::vector<int> a){
        std::cout<<"! ";
        for(auto x:a) std::cout<<x<<" ";
        std::cout<<std::endl;
        return;
    };

    std::vector<int> res(n);
    int v=1;
    for(int i=1;i<=n;i++){
        while(query(i,v)) v++;
        res[i-1]=v;
    }
    print(res);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
