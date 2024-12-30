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
    bool flag=0;
    std::vector<int> y(n+2);
    for(int i=1;i<=n;i++) std::cin>>y[i];
    auto check=[&](int l,int r){
        std::vector<int> st(n+2,0);
        int aa=y[r]-y[l],bb=r-l;
        for(int i=1;i<=n;i++){
            int c=(i<=l ? y[l]-y[i] : y[i]-y[l]);
            int len=std::abs(l-i);
            if(c*bb==aa*len) st[i]=1;
        }
        int cl=l;
        for(int i=1;i<=n;i++){
            if(!st[i]) {
                l=i;
                break;
            }
        }
        if(l==cl) return 0;
        for(int i=1;i<=n;i++){
            if(st[i]) continue;
            int c=(i<=l ? y[l]-y[i] : y[i]-y[l]);
            int len=std::abs(l-i);
            if(c*bb==aa*len) st[i]=1;
            else return 0;
        }
        return 1;
    };
    for(int i=2;i<=n;i++){
        if(check(1,i)) flag=1;
    }
    if(check(2,3)) flag=1;
    if(flag) std::cout<<"Yes"<<"\n";
    else std::cout<<"No"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
