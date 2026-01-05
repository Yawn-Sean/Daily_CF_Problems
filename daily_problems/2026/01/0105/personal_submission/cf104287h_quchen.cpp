#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
int n;
ll dp[N];
ll pw2[N];

void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    for(int i=1;i<n;i++)
    {
        ll cnt = pw2[i];
        ll ecnt = (pw2[n]-pw2[n-i])*(pw2[n-i]-1)%mod*2*cnt%mod;
        // cout<<ecnt<<'\n';
        ans += ecnt;
        ans%=mod;
    }
    cout<<ans<<'\n';

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pw2[0]=1;
    for(int i=1;i<=N-10;i++)
    {
        pw2[i] = pw2[i-1]*2%mod;
    }
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
