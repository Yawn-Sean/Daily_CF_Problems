#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
#define int long long
#define endl '\n'
int n,m;
void solve()
{
	cin>>n>>m;
	int l=0,r=0;
	map<int,int>pos,cnt;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pos[a[i]]=i;
		cnt[a[i]]++;
	}
	int ans=0,maxn=0;
	for(int i=0;i<n;i++)
	{
		if(r<i)
		{
			ans+=r-l+1-maxn;
			r=l=i;maxn=0;
		}
		if(pos[a[i]]>r) r=pos[a[i]];
		if(maxn<cnt[a[i]]) maxn=cnt[a[i]];
	}
	ans+=r-l+1-maxn;
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
