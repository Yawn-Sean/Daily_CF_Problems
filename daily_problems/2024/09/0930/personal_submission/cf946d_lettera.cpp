#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    const int inf = 1e9;
    vector<vector<int>> dp1(n, vector<int>(k + 1, inf));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vector<int> a;
        for (int i = 0; i < m; i++)
        {
            if (s[i] == '1')
            {
                a.push_back(i);
            }
        }
        int nn = a.size();
        if(nn==0)
        {
        	  dp1[i][nn]=0;
        }
        if(nn<=k)
            dp1[i][nn]=0;
        for (int j = 0; j < nn; j++)
        {
            for (int x = nn - 1; x >= j; x--)
            {
                int cnt = j + (nn - 1 - x);
                if(cnt>k)
                {
                	continue;
                }
                dp1[i][cnt] = min(dp1[i][cnt], a[x] - a[j] + 1);
            }
             
        }
    }
    vector<int> dp(k + 1,inf);
    dp[0]=0;//dp[i]表示前几天翘了i节课的最小上课时间
    for (int i = 0; i < n; i++)
    {
    	vector<int>tmp(k+1,inf);
        for (int j = 0; j <= k; j++)
        {
        	for(int x=k-j;x>=0;x--)
        	{
        		tmp[j+x]=min(tmp[j+x],dp[j]+dp1[i][x]);
        	}
        	 
        }
        dp.swap(tmp);
    }
    int ans=dp[k];
    for(int i=0;i<=k;i++)
    {
    	ans=min(ans,dp[i]);
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
