#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod = 1e9+7;
typedef long long ll;
int n;
ll dp[N][N];

void solve()
{
    cin>>n;
    ll ans = 0;    
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int cur = 0;
        vector<ll>dp2(n+1,0);
        for(int j=0;j<=n;j++)
        {
            cur = (cur+j)%i;
            dp[i][j] = dp2[cur];
            dp2[cur] = (dp2[cur]+dp[i-1][j])%mod;
        }
        ans += dp[i][n];
        ans%=mod;
    }

    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
