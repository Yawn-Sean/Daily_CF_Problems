#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<int>a(n);
	map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		for(int j=0;j<=m;j++) 
		{
			mp[j*a[i]]=j;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x;cin>>x;
			int ans=m+1;
		for(auto &p:mp)
		{
			int k=p.first;
			int y=p.second;
		
			if(mp.count(x-k)) 
			{
				ans=min(ans,y+mp[x-k]);
			}
		}
		cout<<(ans>m?-1:ans)<<endl;
	}
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
 } 
