#include <bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
const int mod=1E9+7;
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	ll ans=0;
	//考虑第i位贡献的逆序对数
	vector<ll>q(2*n+1,1);
	for(int i=1;i<=n;i++)
	{
		q[i]=q[i-1]*4%mod;
	}
	for(int i=0;i<n;i++)
	{
		int x=s[n-1-i]-'0';
		ans=(ans*2+(x?q[i]:0))%mod;
		//cerr<<ans<<"\n";
	}
	cout<<ans<<"\n";
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
    return 0;
}
