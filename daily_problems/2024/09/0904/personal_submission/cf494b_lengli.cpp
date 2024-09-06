/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::string s,p;
    std::cin>>s>>p;
    auto q=KMP(s,p);
    int n=s.size(),m=p.size();
    std::vector<Mint> f(n+2,0),pre(n+2,0),ipre(n+2,0);
    std::vector<int> la(n+2,-1);
    for(int i=1,j=-1;i<=n;i++){
        if(q[i]) j=i-m+1;
        la[i]=j;
    }
    for(int i=1;i<=n;i++){
        if(la[i]==-1) f[i]=0;
        else{
            f[i]=la[i];
            f[i]+=1ll*la[i]*(pre[la[i]-1]);
            f[i]-=ipre[la[i]-1];
        }
        pre[i]=pre[i-1]+f[i];
        ipre[i]=ipre[i-1]+1ll*i*f[i];
    }
    Mint res=0;
    for(int i=1;i<=n;i++) res+=f[i];
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
