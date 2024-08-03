// Problem: D. Reverse Madness
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1878/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int l[N],r[N];
int n;
void solve(){
	int n,m;
	cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	vector<int>c(n+15);
	for(int i=1;i<=m;i++)cin>>l[i];
	for(int i=1;i<=m;i++)cin>>r[i];
	int q;cin>>q;
	while(q--){
		int x;cin>>x;
		//cout<<x<<"\n";
		int t=upper_bound(l+1,l+1+m,x)-l-1;
		int ll=min(x,l[t]+r[t]-x);
		int rr=max(x,l[t]+r[t]-x);
		//cout<<ll<<" "<<rr<<"\n";
		c[ll]++;c[rr+1]--;
	}
	for(int i=1;i<=n;i++)c[i]+=c[i-1];
	for(int i=1;i<=m;i++)
		for(int j=l[i];j<=(r[i]+l[i])/2;j++){
			if(c[j]%2==1)
				swap(s[j],s[r[i]+l[i]-j]);
		}
	for(int i=1;i<=n;i++)
		cout<<s[i];
	cout<<"\n";
	
	
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt;cin>>tt;
	while(tt--)solve();
}


