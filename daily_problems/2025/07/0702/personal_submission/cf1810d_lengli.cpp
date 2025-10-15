/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

#define int long long

constexpr i64 inf=1e18;

void solve(){
    int n;
    std::cin>>n;
    i64 l=0,r=inf;
    for(int i=1;i<=n;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int a,b,n;
            std::cin>>a>>b>>n;
            int cl,cr;
            if(n==1) cl=1,cr=a;
            else cl=(a-b)*(n-2)+a+1,cr=(a-b)*(n-1)+a;
            int nl=std::max(l,cl),nr=std::min(r,cr);
            if(nl>nr) std::cout<<0<<" ";
            else{
                l=nl,r=nr;
                std::cout<<1<<" ";
            }
        }else{
            int a,b;
            std::cin>>a>>b;
            int p=std::max(1ll,(l-b-1)/(a-b)+1);
            int q=std::max(1ll,(r-b-1)/(a-b)+1);
            if(p==q) std::cout<<p<<" ";
            else std::cout<<"-1"<<" ";
        }
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
