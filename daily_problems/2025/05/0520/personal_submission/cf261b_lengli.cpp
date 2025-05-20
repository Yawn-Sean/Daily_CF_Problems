/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define f128 long double

constexpr int N=55;

int n,p;
int a[N];
f128 f[N][N][N];

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::cin>>p;
    f[1][1][a[1]]=1;
    f[1][0][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=p;k++){
                f[i][j][k]+=f[i-1][j][k];
                if(j>=1 and k>=a[i]) f[i][j][k]+=f[i-1][j-1][k-a[i]];
            }
        }
    }

    std::vector<f128> fac(n+2);
    fac[0]=1.0;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
    f128 res=0;
    for(int j=1;j<=n;j++){
        for(int k=0;k<=p;k++){
            res+=fac[j]*fac[n-j]*f[n][j][k];
        }
    }
    res/=fac[n];
    std::cout<<std::fixed<<std::setprecision(10)<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
