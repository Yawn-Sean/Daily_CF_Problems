/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

int n,m,q;
int a[41][41];
int f[41][41][41][41];

int sum(int x,int y,int l,int r){
    return a[l][r]+a[x-1][y-1]-a[l][y-1]-a[x-1][r];    
}

void solve(){
    std::cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            a[i][j]=c=='1';
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]+=a[i][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]+=a[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int x=i;x<=n;x++){
                for(int y=j;y<=m;y++){
                    f[i][j][x][y]=f[i][j][x-1][y]+f[i][j][x][y-1]-f[i][j][x-1][y-1];
                    f[i][j][x][y]+=sum(i,j,x,y)==0;
                }
            }
    
    while(q--){
        int x,y,a,b;
        std::cin>>x>>y>>a>>b;
        int res=0;
        for(int i=x;i<=a;i++){
            for(int j=y;j<=b;j++){
                res+=f[i][j][a][b];
            }
        }
        std::cout<<res<<"\n";

    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
