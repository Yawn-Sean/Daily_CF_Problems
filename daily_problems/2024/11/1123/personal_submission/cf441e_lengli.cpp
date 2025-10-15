/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int x,k,p;
    std::cin>>x>>k>>p;
    std::vector<std::vector<double>> f(k+2,std::vector<double> (k+2,0));

    for(int i=0;i<=k;i++) f[0][i]=__builtin_ctz(x+i);
    double mul=(double)p/100.0;
    double add=1.0-mul;
    for(int i=1;i<=k;i++){
        for(int j=0;j<=k;j++){
            f[i][j]=f[i-1][j+1]*add;
            if(j%2==0) f[i][j]+=(f[i-1][j>>1]+1)*mul;
        }
    }
    std::cout<<std::fixed<<std::setprecision(10)<<f[k][0]<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
