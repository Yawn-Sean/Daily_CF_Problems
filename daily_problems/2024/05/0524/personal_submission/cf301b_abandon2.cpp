#include<bits/stdc++.h>
using namespace std;
const int N=200,inf=1e9;
int f[N][N],a[N],x[N],y[N];
int n,d;

void solve(){
    cin>>n>>d;
    for(int i=2;i<=n-1;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        //cout<<x[i]<<" "<<y[i]<<"\n";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            f[i][j]=inf;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            f[i][j]=(abs(x[j]-x[i])+abs(y[j]-y[i]))*d-a[j];
            f[j][i]=(abs(x[j]-x[i])+abs(y[j]-y[i]))*d-a[i];
        }
   
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i!=j&&i!=k&&j!=k)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
    }
    cout<<f[1][n]<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
