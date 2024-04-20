#include <bits/stdc++.h>
using  namespace std;
const int N=2e5+10;
#define int long long 
#define endl '\n'
typedef pair<int, int> PII;
int n,m;
char  s[N];
void solve()
{
    cin>>n>>m;
    cin>>(s+1);
    vector<PII>v(m+1);
    for(int i=1;i<=m;i++) cin>>v[i].first;
    for(int i=1;i<=m;i++) cin>>v[i].second;
    vector<bool>vis(n+1);
    vector<int>d(n+2);
    int k;
    cin>>k;
    while(k--)
    {
    	int x;cin>>x;
    	int l=1,r=m+1;
    	while(l<r)
    	{
    		int mid=(l+r)/2;
    		if(v[mid].second>=x) r=mid;
    		else l=mid+1;
 		}
 		int a=min(x,v[l].first+v[l].second-x);
 		int b=max(x,v[l].first+v[l].second-x);
 		d[a]++;d[b+1]--; 
	}
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(v[cnt].second<i) cnt++;
		if(d[i]&1)
		{
			if(vis[i]) continue;
			vis[i]=vis[v[cnt].first+v[cnt].second-i]=1;
			swap(s[i],s[v[cnt].first+v[cnt].second-i]);
		}
	}
	cout<<(s+1)<<endl; 
}
signed main()
{
	 ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--) solve();
    return 0;
}
