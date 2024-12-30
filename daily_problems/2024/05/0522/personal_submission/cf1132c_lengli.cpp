#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define all(a) a.begin(),a.end()

using namespace std;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> b(n+2,0);
	vector<array<int,2>> a(q);
	for(auto &[l,r]:a) cin>>l>>r,b[l]++,b[r+1]--;
	
	vector<int> o(n+2,0),t(n+2,0);
	for(int i=1;i<=n;i++) {
		b[i]+=b[i-1];
		if(b[i]==1) o[i]=1;
		else if(b[i]==2) t[i]=1;
	}
	for(int i=1;i<=n;i++) {
		o[i]+=o[i-1],t[i]+=t[i-1];
	}
	auto get=[&](int i,int j){
		int res=0;
		auto [u,v]=a[i];
		auto [x,y]=a[j];
		res+=o[v]-o[u-1]+o[y]-o[x-1];
		if(v<x or y<u) return res;
		int xx=max(x,u),yy=min(y,v);
		if(xx<=yy) res+=t[yy]-t[xx-1];
		return res;
	};
	
	int sum=0;
	for(int i=1;i<=n;i++) if(b[i]) sum++;
	
	int res=0;
	for(int i=0;i<q;i++)
		for(int j=i+1;j<q;j++){
			res=max(res,sum-get(i,j));
		}
	cout<<res;
}

signed main(){
	fastio;
	
	int T;
	T=1;
	while(T--) solve();
	
	return 0;
}
