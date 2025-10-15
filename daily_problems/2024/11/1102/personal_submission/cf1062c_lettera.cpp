#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int N=2E5+5;
int p[N];
const int mod=1e9+7;
ll MOD(ll x)
{
	return (x%mod+mod)%mod;
}
void solve()
{
       int n,q;
       cin>>n>>q;
       p[0]=1;
       vector<int>cnt1(n+1),cnt0(n+1);
       for(int i=1;i<N;i++)
       {
       	 p[i]=MOD(p[i-1]*2);
       }
       string s;
       cin>>s;
       s=" "+s;
       for(int i=1;i<=n;i++)
       {
       	 cnt1[i]=cnt1[i-1]+(s[i]=='1');
       	 cnt0[i]=cnt0[i-1]+(s[i]=='0');
       }
       while(q--)
       {
       	int l,r;
       	cin>>l>>r;
       	int c1=cnt1[r]-cnt1[l-1];
       	int c0=cnt0[r]-cnt0[l-1];
       	int ans=MOD(p[c1+c0]-p[c0]);
       	cout<<ans<<"\n";
       }
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
