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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    int D=sqrt(n);
    std::vector<std::vector<std::array<int,2>>> qr(D+1);
    int m;
    std::cin>>m;
    std::vector<int> res(m+2);
    for(int i=1;i<=m;i++){
        int x,len;
        std::cin>>x>>len;
        if(len<=D) qr[len].pb({x,i});
        else{
            int sum=0;
            for(int i=x;i<=n;i+=len) sum+=a[i];
            res[i]=sum;
        }
    }
    for(int i=1;i<=D;i++){
        if(qr[i].empty()) continue;
        std::vector<int> f(n+2,0);
        for(int j=n;j>=1;j--){
            if(j+i>n) f[j]=a[j];
            else f[j]=a[j]+f[i+j];
        }
        for(auto [x,id]:qr[i]) res[id]=f[x];
    }
    for(int i=1;i<=m;i++) std::cout<<res[i]<<"\n";
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
