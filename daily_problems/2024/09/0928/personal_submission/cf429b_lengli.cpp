/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long

int a[1010][1010];
int f[5][1010][1010];

void solve(){
    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) std::cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) f[1][i][j]=std::max(f[1][i-1][j],f[1][i][j-1])+a[i][j];
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++) f[2][i][j]=std::max(f[2][i+1][j],f[2][i][j-1])+a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--) f[3][i][j]=std::max(f[3][i-1][j],f[3][i][j+1])+a[i][j];
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--) f[4][i][j]=std::max(f[4][i+1][j],f[4][i][j+1])+a[i][j];
    int res=0;
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++) {
            int ans=f[1][i-1][j]+f[4][i+1][j];
            ans+=f[2][i][j-1]+f[3][i][j+1];
            res=std::max(res,ans);
            ans=f[1][i][j-1]+f[4][i][j+1];
            ans+=f[2][i+1][j]+f[3][i-1][j];
            res=std::max(res,ans);
        }
        
    std::cout<<res<<"\n";
        
            
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
