#include <iostream>
#include <valarray>
using namespace std;
const int MAXN=2e5+50;
#define ll long long int
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll dp[MAXN]={0};
    ll sum=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i]+sum)%m;
        ll cur=0;
        for(int l=2,r;l<=i;l=r+1){
            r=i/(i/l);
            cur=(cur+dp[i/l]*(r-l+1)%m)%m;
        }
        dp[i]=(dp[i]+cur)%m;
        sum=(dp[i]+sum)%m;
    }
    cout<<dp[n]<<endl;
    return 0;
}
