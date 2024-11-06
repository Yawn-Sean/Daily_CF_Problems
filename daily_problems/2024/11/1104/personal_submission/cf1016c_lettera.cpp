#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
	int n;
	cin>>n;
	vector<int>a(n+1),b(n+1);
	vector<int>prea(n+1),preb(n+1);
	vector<int>dp1(n+2),dp2(n+2);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		prea[i]=prea[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		preb[i]=preb[i-1]+b[i];
	}
	for(int i=n;i>=1;i--)
	{
		 dp1[i]=dp1[i+1]-(prea[n]-prea[i])-(preb[n]-preb[i])+(2*i-2)*a[i]+(2*n-1)*b[i];
		 dp2[i]=dp2[i+1]-(prea[n]-prea[i])-(preb[n]-preb[i])+(2*i-2)*b[i]+(2*n-1)*a[i];
	}
	int ans=dp1[1];
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			cur+=(2*i-2)*a[i]+(2*i-1)*b[i];
			ans=max(ans,cur+dp2[i+1]);
		}
		else
		{
			cur+=(2*i-2)*b[i]+(2*i-1)*a[i];
			ans=max(ans,cur+dp1[i+1]);
		}
	}
	cout<<ans;
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
