#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,inf=2e18+1;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,a[N],last[N],m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]!=1) last[i]=i-1;
		else last[i]=last[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i],mul=a[i];
		if(mul==sum*m) ans++;
		for(int pre=last[i],now=i;;now=pre,pre=last[pre])
		{
			int t=mul-sum*m;
			// mul/(sum+x)=m   mul-m*sum = m*x 
			if(t>0&&t%m==0&&t/m<now-pre) ans++;
			if(!pre||mul>inf/a[pre]) break;
			mul*=a[pre];sum+=a[pre]+(now-pre-1);
			if(mul==sum*m) ans++;
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
