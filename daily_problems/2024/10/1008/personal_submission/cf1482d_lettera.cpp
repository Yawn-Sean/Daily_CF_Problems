#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> pre(n), suf(n);
    iota(pre.begin(), pre.end(), -1);
    iota(suf.begin(), suf.end(), 1);
    pre[0] = n - 1;
    suf[n - 1] = 0;
    queue<int> q;
    vector<int> vis(n);
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (!vis[u])
        {
        	int v=suf[u];
        	if(__gcd(a[u],a[v])==1)
        	{
        		vis[v]=1;
        		ans.push_back(v);
        		suf[u]=suf[v];
        		q.push(u);
        		 
        	}
        }
    }
    cout<<ans.size()<<" ";
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
