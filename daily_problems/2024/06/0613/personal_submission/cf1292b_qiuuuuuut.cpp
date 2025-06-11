#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=1e9+7;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n;
void solve()
{
	int x0,y0,ax,bx,ay,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t;
	int x=x0,y=y0;
	vector<int>v1,v2;
	while(x-xs+y-ys<=t)
	{
		v1.push_back(x);
		v2.push_back(y);
		x=x*ax+bx;
		y=y*ay+by;
	}
	int ans=0;
	n=v1.size();
	// (xs,ys) -> i ->(j|k) ->[j,k]
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=i;k<n;k++)
			{
			    if(abs(xs-v1[i])+abs(ys-v2[i])+v1[k]-v1[j]+v2[k]-v2[j]+min(v1[i]-v1[j]+v2[i]-v2[j],v1[k]-v1[i]+v2[k]-v2[i])<=t) 
				ans=max(ans,k-j+1);	
			}
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
