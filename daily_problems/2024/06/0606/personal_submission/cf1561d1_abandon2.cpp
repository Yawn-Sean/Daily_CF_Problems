#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
//#define int long long
typedef long long LL;
LL f[N],sum[N];

void solve(){
    int n,md;cin>>n>>md;
    f[n]=1;sum[n]=1;
    for(int i=n;i>=1;i--){
        f[i]=(f[i]+sum[i+1])%md;
        for(int j=2;i*j<=n;j++){
            f[i]=(f[i]+sum[i*j]-sum[min(i*j+j,n+1)])%md;
            f[i]+=md;f[i]%=md;
        }
        sum[i]=(sum[i+1]+f[i])%md;
    }
    cout<<f[1]<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
