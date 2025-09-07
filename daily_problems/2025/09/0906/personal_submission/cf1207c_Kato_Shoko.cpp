#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,a,b;
    string s;
    cin>>n>>a>>b>>s;

    vector<vector<ll>>dp(n+1,vector<ll>(2,inf));
    dp[0][0]=b;
    dp[0][1]=inf;
    s="!"+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            dp[i][0]=min(dp[i-1][0]+b+a,dp[i-1][1]+b+a+a);
            dp[i][1]=min(dp[i-1][0]+a+a+b+b,dp[i-1][1]+a+b+b);
        }else{
            dp[i][1]=dp[i-1][1]+a+b+b;
        }
    }
    cout<<dp[n][0]<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
