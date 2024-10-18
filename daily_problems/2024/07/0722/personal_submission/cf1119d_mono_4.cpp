#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
const int N=1e3+5;
void solve() {
	int n;cin>>n;
	vector<int>a(n+1),d(n+1),p(n+1);
	rep(i,1,n) cin>>a[i];
	sort(a.begin()+1,a.end());
	rep(i,2,n){
		d[i]=a[i]-a[i-1]; 
	}
	sort(d.begin()+2,d.end());
	rep(i,2,n){
		p[i]=p[i-1]+d[i]-1;
	}
	int m;cin>>m;
	rep(i,1,m){
		int l,r;cin>>l>>r;
		int sz=r-l;
		int t=upper_bound(d.begin()+2,d.end(),sz)-d.begin();
		int ans=p[t-1]+sz+n+(n-t+1)*sz;
		cout<<ans<<" \n"[i==m];
	}
}
signed main() {
	solve();
	return 0;
}
