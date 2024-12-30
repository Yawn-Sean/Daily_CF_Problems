/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

int n,a,b;
int h[210];
int f[210][40010][2];
int pre[210];

void solve(){
    std::cin>>n>>a>>b;
    for(int i=1;i<=n;i++) {
        std::cin>>h[i];
        pre[i]=pre[i-1]+h[i];
    }

    for(int i=0;i<=n;i++)
        for(int j=0;j<=40000;j++)
            for(int k=0;k<2;k++) f[i][j][k]=inf;

    f[0][0][0]=0;
    f[0][0][1]=0;


    for(int i=1;i<=n;i++){
        int sum=pre[i];
        int d=std::min(h[i],h[i-1]);
        for(int j=0;j<=a;j++){
            if(sum-j<=b) f[i][j][1]=std::min(f[i-1][j][0]+d,f[i][j][1]);
            if(sum-j<=b) f[i][j][1]=std::min(f[i-1][j][1],f[i][j][1]);
        }
        for(int j=h[i];j<=a;j++){
            f[i][j][0]=std::min(f[i-1][j-h[i]][0],f[i][j][0]);
            f[i][j][0]=std::min(f[i-1][j-h[i]][1]+d,f[i][j][0]);
        }
    }

    int res=inf;
    for(int j=0;j<=a;j++)
        for(int k=0;k<2;k++) res=std::min(res,f[n][j][k]);
    if(res==inf) res=-1;
    std::cout<<res<<"\n";
}

signed main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
