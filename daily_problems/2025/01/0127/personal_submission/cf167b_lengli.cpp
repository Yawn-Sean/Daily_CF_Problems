/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=210;

int n,l,m;
int p[N],a[N];
double f[N][N][N*2];

void solve(){
    std::cin>>n>>l>>m;
    for(int i=1;i<=n;i++) std::cin>>p[i];
    for(int i=1;i<=n;i++) std::cin>>a[i];

    f[0][0][m+200]=1.0;
    for(int i=0;i<n;i++){
        double win=0.01*p[i+1],loss=1.0-win;
        for(int j=0;j<=i;j++){
            for(int k=0;k<=400;k++){
                if(f[i][j][k]>0 and k+a[i+1]>=0){
                    f[i+1][j+1][std::min(k+a[i+1],400)]+=f[i][j][k]*win;
                }
                if(f[i][j][k]>0){
                    f[i+1][j][k]+=f[i][j][k]*loss;
                }
            }
        }
    }
    double res=0;
    for(int j=l;j<=n;j++){
        for(int k=200;k<=400;k++){
            res+=f[n][j][k];
        }
    }
    std::cout<<std::fixed<<std::setprecision(12)<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
