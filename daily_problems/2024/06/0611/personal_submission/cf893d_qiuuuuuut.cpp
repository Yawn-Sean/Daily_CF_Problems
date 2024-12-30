#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,a[N],b[N],d;
void solve()
{
	cin>>n>>d;
	int l=0,r=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(!x)
		{
			l=max(l,0LL);
			if(r<0)
			{
				ans++;
				r=d; 
			}
		}
		else
		{
			l+=x;r+=x;
			if(l>d)
			{
				ans=-1;break;
			}
			r=min(r,d);
		}
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
