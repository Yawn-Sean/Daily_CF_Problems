#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
#define int long long
#define endl '\n'
int n;
int tr[N+10];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int k)
{
	for(int i=x;i<=N;i+=lowbit(i)) tr[i]+=k;
}
int sum(int x)
{
	int res=0;
	for(int i=x;i>0;i-=lowbit(i)) res+=tr[i];
	return res;
}
void solve()
{
	cin>>n;
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++)
	{
		tr[i+1]=0;cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	map<int,int>mp,cnt;
	int id=0;
	for(int x:b) mp[x]=++id;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int x=i-sum(mp[a[i]]);
		int y=sum(mp[a[i]])-cnt[a[i]];
		ans+=min(x,y);
		add(mp[a[i]],1);
		cnt[a[i]]++;
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}
