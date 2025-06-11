#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1),b(n+1),c(n+2), l(n + 1), r(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cur = -1;
    for (int i = 1; i <= n; i++)
    {
        l[i] = l[i - 1];
        if (a[i] > cur)
        {
            cur = a[i];
        }
        else
        {
        	l[i]+=cur+1-a[i];
        	cur++;
        }
        b[i]=cur;
    }
    cur=-1;
    for (int i = n; i>=1; i--)
    {
        r[i] = r[i+1];
        if (a[i] > cur)
        {
            cur = a[i];
        }
        else
        {
        	r[i]+=cur+1-a[i];
        	cur++;
        }
        c[i]=cur;
    }
    int ans=1E18;
    for(int i=1;i<=n;i++)
    {
    	int res=max({0ll,-a[i]+b[i-1]+1,1-a[i]+c[i+1]});
    	ans=min(ans,l[i-1]+r[i+1]+res);
    }
    cout<<ans;
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
