#include<bits/stdc++.h>
using namespace std;

const int N=2e3+10,md=998244353;
typedef long long LL;
LL f[N][N][4];//第i列，当前的连通块为k,第i列的状态为t
int a[4];

void solve(){
    cout<<a[-2]<<"\n";
    
    int n,k;cin>>n>>k;    
    f[1][1][0]=1;
    f[1][2][1]=1;
    f[1][2][2]=1;
    f[1][1][3]=1;
    
    auto mul=[&](LL &x)->LL{
        x%=md;
        return x;
    };

    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            f[i][j][0]=mul(f[i-1][j][0])+mul(f[i-1][j][1])+mul(f[i-1][j][2])+(j<1?0LL:mul(f[i-1][j-1][3]));
            mul(f[i][j][0]);
            f[i][j][1]=(j<1?0LL:mul(f[i-1][j-1][0]))+mul(f[i-1][j][1])+(j<2?0LL:mul(f[i-1][j-2][2]))+(j<1?0LL:mul(f[i-1][j-1][3]));
            mul(f[i][j][1]);
            f[i][j][2]=(j<1?0LL:mul(f[i-1][j-1][0]))+(j<2?0LL:mul(f[i-1][j-2][1]))+mul(f[i-1][j][2])+(j<1?0LL:mul(f[i-1][j-1][3]));
            mul(f[i][j][2]);
            f[i][j][3]=(j<1?0LL:mul(f[i-1][j-1][0]))+mul(f[i-1][j][1])+mul(f[i-1][j][2])+mul(f[i-1][j][3]);            
            mul(f[i][j][3]);
        }
    }   
    LL ans=mul(f[n][k][0])+mul(f[n][k][1])+mul(f[n][k][2])+mul(f[n][k][3]);
    mul(ans);
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
