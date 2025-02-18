/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=510;

int n,m;
int a[N][N];
int f[N][N][16][9];

void solve(){
    std::cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char c;
            std::cin>>c;
            a[i][j]=(c=='*');
        }

    for(int i=1;i+1<=n;i++){
        for(int j=1;j+1<=m;j++){
            int v=a[i][j]+a[i][j+1]*2+a[i+1][j]*4+a[i+1][j+1]*8;
            f[i][j][v][1]=1;
        }
    }
    int res=0;
    for(int k=2;k<9;k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            for(int j=1;j+(1<<k)-1<=m;j++){
                for(int v=0;v<16;v++){
                    bool flag=1;
                    int d=1<<(k-1);
                    flag&=f[i][j][(v&1) ? 15 : v][k-1];
                    flag&=f[i][j+d][(v>>1&1) ? 15 : v][k-1];
                    flag&=f[i+d][j][(v>>2&1) ? 15 : v][k-1];
                    flag&=f[i+d][j+d][(v>>3&1) ? 15 : v][k-1];
                    f[i][j][v][k]=flag;
                    res+=flag;
                }
            }
        }
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
