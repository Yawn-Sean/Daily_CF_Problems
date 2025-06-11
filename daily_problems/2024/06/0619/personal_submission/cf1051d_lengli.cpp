/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

Mint f[1010][3010][4];

void solve(){
    int n,k;
    std::cin>>n>>k;
    f[1][1][0]=1;
    f[1][2][1]=1;
    f[1][2][2]=1;
    f[1][1][3]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            f[i+1][j][0]+=f[i][j][0];
            f[i+1][j+1][1]+=f[i][j][0];
            f[i+1][j+1][2]+=f[i][j][0];
            f[i+1][j+1][3]+=f[i][j][0];

            f[i+1][j][0]+=f[i][j][1];
            f[i+1][j][1]+=f[i][j][1];
            f[i+1][j+2][2]+=f[i][j][1];
            f[i+1][j][3]+=f[i][j][1];
            
            f[i+1][j][0]+=f[i][j][2];
            f[i+1][j+2][1]+=f[i][j][2];
            f[i+1][j][2]+=f[i][j][2];
            f[i+1][j][3]+=f[i][j][2];

            f[i+1][j+1][0]+=f[i][j][3];
            f[i+1][j+1][1]+=f[i][j][3];
            f[i+1][j+1][2]+=f[i][j][3];
            f[i+1][j][3]+=f[i][j][3];
        }
    }
    Mint res=0;
    for(int i=0;i<4;i++) res+=f[n][k][i];

    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
