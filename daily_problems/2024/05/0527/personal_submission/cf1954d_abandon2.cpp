#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,md=998244353;
typedef long long LL;
LL f[N],a[N];
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    LL ans=0,m=5000;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=a[i];j++)
            ans+=1LL*f[j]*a[i]%md;
        ans%=md;
        for(int j=a[i]+1;j<=m;j++)
            ans+=1LL*f[j]*((a[i]+j+1)/2)%md;
        ans%=md;
        for(int j=m;j>=a[i];j--)
            f[j]=(f[j]+f[j-a[i]])%md;
        //cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
