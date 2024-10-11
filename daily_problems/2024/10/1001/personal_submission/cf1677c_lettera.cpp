#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		b[i]--;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[b[i]];
		a[b[i]]--;
	}
	vector<int>vis(n);
	ll cnt=0;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			int res=0;
			while(!vis[i])
			{
				vis[i]=1;
				i=a[i];
				res++;
			}
			cnt+=res/2;
		}
	}
	cout<<2ll*cnt*(n-cnt)<<"\n";
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
