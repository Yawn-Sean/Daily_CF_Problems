#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=55,inf=1e9;
int f[N][M];//前i个数分为j组
int s[N],t[105];
int a[N];
void solve(){
    int n,K,P;cin>>n>>K>>P;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        s[i]=(s[i-1]+a[i])%P;
    }        
    for(int i=1;i<=n;i++)
        for(int j=0;j<=K;j++)
            f[i][j]=-inf;
    
    for(int j=1;j<=K;j++){
        for(int i=0;i<P;i++)t[i]=-inf;
        if(j==1)t[0]=0;
        for(int i=1;i<=n;i++){
            for(int k=0;k<P;k++){
                f[i][j]=max(f[i][j],t[k]+(s[i]-k+P)%P);
                t[s[i]]=max(f[i][j-1],t[s[i]]);
            }
            //cout<<i<<" "<<j<<" "<<f[i][j]<<"   ---\n";
        }
    }
    cout<<f[n][K]<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
