#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
void solve()
{
    int n;
    cin>>n;
    vector<int> dp1(n+10);
    vector<int> dp2(n+10);
    vector<int> a(n+10);
    for(int i=1;i<=n;i++)
        cin>>a[i];

    dp1[1] = 1;
    dp2[n] = 1;
    for(int i=2;i<=n;i++)
        dp1[i] = min(dp1[i-1]+1,a[i]);
    for(int i=n-1;i>=1;i--)
        dp2[i] = min(dp2[i+1]+1,a[i]);
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,min(dp1[i],dp2[i]));
    cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    t=1;
    while (t--)
    {
        solve();
    }
}
