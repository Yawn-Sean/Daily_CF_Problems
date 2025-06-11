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
    i64 n,m,x,y,a,b;
    std::cin>>n>>m>>x>>y>>a>>b;
    i64 d=std::gcd(a,b);
    a/=d,b/=d;
    i64 tmp=std::min(n/a,m/b);
    a*=tmp,b*=tmp;

    i64 down=x-(a+1)/2;
    if(down<0) down=0;
    else if(down+a>n) down-=down-n+a;

    i64 up=y-(b+1)/2;
    if(up<0) up=0;
    else if(up+b>m) up-=up-m+b;
    std::cout<<down<<" "<<up<<" "<<down+a<<" "<<up+b<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
