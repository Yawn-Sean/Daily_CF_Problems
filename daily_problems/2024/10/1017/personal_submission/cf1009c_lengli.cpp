/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m;
    std::cin>>n>>m;
    long long sum=0,mx=0,mi=0;
    int idx=(n+1)/2;
    for(int i=1;i<=n;i++){
        mx+=(i-1);
        if(i<idx) mi+=idx-i;
        else if(i>idx) mi+=i-idx;
    }

    for(int i=1;i<=m;i++){
        int x,d;
        std::cin>>x>>d;
        long long l=x*n+mx*d;
        long long r=x*n+mi*d;
        sum+=std::max(l,r);
    }
    std::cout<<std::fixed<<std::setprecision(10)<<(double)sum/n<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
