#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n + 1);
    int M = 5005;
    vector<int> ls(M, n), rs(M, 1);
    for (int i = 1; i <= n; i++)
    {
        ls[a[i]] = min(ls[a[i]], i);
        rs[a[i]] = max(rs[a[i]], i);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<int> vis(M);
        int cur=0,r=0;
        for (int j = i; j <= n; j++)
        {
            if (ls[a[j]] < i)
            {
                break;
            }
            else
            {
            	if(!vis[a[j]])
            	{
            		cur^=a[j];
            		vis[a[j]]=1;
            	}
            	r=max(r,rs[a[j]]);
            	if(j==r)
            	{
            		dp[j]=max(dp[j],dp[i-1]+cur);
            	}
            }
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
