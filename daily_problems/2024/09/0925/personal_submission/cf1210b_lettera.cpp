#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
	//挑选一个数后，可以把这个数的所有子集都挑选上
	//如果一个数出现两次，这两个数都可以加入ans
    int n;
    cin >> n;
    vector<ll>a(n),b(n),use(n);
    ll ans=0;
    map<ll,int>cnt;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	cnt[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
    	cin>>b[i];
    }
    for(auto [x,y]:cnt)
    {
    	if(y>1)
    	{
    		for(int i=0;i<n;i++)
    		{
    			if(use[i]==0&&((a[i]|x)==x))
    			{
    				ans+=b[i];
    				use[i]=1;
    			}
    		}
    	}
    }
    cout << ans << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}
