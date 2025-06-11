#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=1e9+7;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,a[N],id[N],k,p,f[N];
void solve()
{
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=(a[i-1]+a[i])%p;
	} 
	for(int i=1;i<=n;i++) 
	{
		for(int j=k-1;j>0;j--)
		{
			int t=f[j-1]+(a[i]-a[id[j-1]]+p)%p;
			if(t>f[j])
			{
				f[j]=t;id[j]=i;
			}
		}
	}
	cout<<f[k-1]+(a[n]-a[id[k-1]]+p)%p;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
