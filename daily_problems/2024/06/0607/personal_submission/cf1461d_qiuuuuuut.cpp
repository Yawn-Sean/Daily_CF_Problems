#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
#define int long long
#define endl '\n'
int n,m; 
int a[N],s[N];
map<int,int>mp;
typedef pair<int,int> PII;
map<PII,int>ha;
void dfs(int x,int y)
{
	if(x>y) return;
	if(ha.count({x,y})) return;
	ha[{x,y}]=1;
	if(x==y) 
	{
		mp[a[x]]=1;
		return;
	}
	int hh=s[y]-s[x-1];
	mp[hh]=1;
	int mid=(a[x]+a[y])/2;
	int it=upper_bound(a+x,a+y+1,mid)-(a+1);
	dfs(x,it);
	dfs(it+1,y);
}
void solve()
{
	cin>>n>>m;
	mp.clear();
	ha.clear();
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	dfs(1,n);
	while(m--)
	{
		int x;cin>>x;
		if(mp.count(x)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}   
signed main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}
