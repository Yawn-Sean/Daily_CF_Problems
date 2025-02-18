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
    std::string s;
    std::cin>>n>>s>>m;
    std::vector<int> f(n+2),g(n+2),p(n+2);
    std::vector<std::vector<int>> l(2,std::vector<int> (n+2,0));
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+(s[i-1]=='?');
        if(s[i-1]!='a') l[0][i]=l[1][i-1]+1;
        if(s[i-1]!='b') l[1][i]=l[0][i-1]+1;
        f[i]=f[i-1];
        g[i]=g[i-1];
        if(l[m&1][i]>=m){
            if(f[i]<f[i-m]+1){
                f[i]=f[i-m]+1;
                g[i]=g[i-m]+p[i]-p[i-m];
            }else if(f[i]==f[i-m]+1){
                g[i]=std::min(g[i],g[i-m]+p[i]-p[i-m]);
            }
        }
    }
    std::cout<<g[n]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
