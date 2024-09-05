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
    int n,m,k;
    std::cin>>n>>m>>k;
    if(n-1+m-1<k) {
        std::cout<<"-1"<<"\n";
        return;
    }
    int res=-1;
    for(int l=1,r;l<=n;l=r+1){
        r=n/(n/l);
        int cnt=std::min(k,r-1);
        int a=n/(cnt+1),b=m/(k-cnt+1);
        res=std::max(res,a*b);
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
