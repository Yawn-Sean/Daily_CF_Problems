/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

void solve(){
    int n,x;
    std::cin>>n>>x;
    int res=0;
    int l=x,r=x;
    for(int i=1;i<=n;i++){
        int a,b;
        std::cin>>a>>b;
        if(a>r){
            res+=a-r;
            l=r,r=a;
        }else if(b<l){
            res+=l-b;
            r=l;l=b;
        }else{
            l=std::max(l,a);
            r=std::min(r,b);
        }
    }
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
