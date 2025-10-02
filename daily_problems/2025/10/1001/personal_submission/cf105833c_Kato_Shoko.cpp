#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<ll>h(n+1),d(n+1),c(n+1);
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++)cin>>c[i];

    vector<vector<ll>>dp(n+2,vector<ll>(5002,-inf));
    //dp[i][j]:区间[i,n]右侧已选的总d等于j时候，获得的最大收益 伤害-费用

    dp[n+1][0]=0;

    for(int i=n;i>=1;i--){
        for(ll j=0;j<=5000;j++){
            ll base=dp[i+1][j];
            if(base==-inf)continue;

            ll val=base+min(h[i],j);
            dp[i][j]=max(dp[i][j],val);

            ll nj=j+d[i];
            nj=min(nj,5000ll);
            val=base+min(h[i],nj)-c[i];
            dp[i][nj]=max(dp[i][nj],val);
        }
    }

    cout<<*max_element(dp[1].begin(),dp[1].end());
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
