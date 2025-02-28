/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=5010,inf=2e9;

int n,k;
int a[N];
int f[N][N][3];

void solve(){
    std::cin>>n;
    k=(n+1)/2;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=0;i<=n+2;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<3;k++) f[i][j][k]=inf;

    f[1][1][1]=0;
    f[1][0][0]=0;
    f[0][0][0]=0;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            f[i][j][0]=std::min(f[i-1][j][1]+std::max(0,a[i]-a[i-1]+1),f[i-1][j][0]);
            f[i][j][1]=std::min(f[i-2][j-1][0]+std::max(a[i-1]-a[i]+1,0),f[i-2][j-1][1]+std::max(0,a[i-1]-std::min(a[i-2],a[i])+1));
        }
    }

    for(int i=1;i<=k;i++){
        std::cout<<std::min(f[n][i][0],f[n][i][1])<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
