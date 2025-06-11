/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=1010;

int f[11][N][N];

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::string a,b;
    std::cin>>a>>b;
    
    for(int t=1;t<=k;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    f[t][i][j]=std::max(f[t][i-1][j-1],f[t-1][i-1][j-1])+1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[t][i][j]=std::max(f[t][i][j],f[t][i-1][j]);
                f[t][i][j]=std::max(f[t][i][j],f[t][i][j-1]);
            }
        }
    }

    std::cout<<f[k][n][m]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
