#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"

//

void solve() {
	int n,k;
	cin>>n>>k;
	vector<vector<int>>adj(n+1);
	int u,v;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int mxn=0;
	vector<int>dp1(n+1),dp2(n+1);
	auto wk1=[&](auto self,int u,int v)->void{
		dp1[v]=dp1[u]+1;
		mxn=max(mxn,dp1[v]);
		for(auto &k:adj[v]){
			if(k!=u){
				self(self,v,k);
			}
		}
	};
	auto wk2=[&](auto self,int u,int v)->void{
		dp2[v]=dp2[u]+1;
		mxn=max(mxn,dp2[v]);
		for(auto &k:adj[v]){
			if(k!=u){
				self(self,v,k);
			}
		}
	};
	wk1(wk1,0,1);
	int mxx=0,x=0,mxy=0,y=0;
	for(int i=1;i<=n;++i){
		if(dp1[i]>mxx){
			x=i;
		}
		mxx=max(mxx,dp1[i]);
	}
	wk2(wk2,0,x);
	for(int i=1;i<=n;++i){
		if(dp2[i]>mxy){
			y=i;
		}
		mxy=max(mxy,dp2[i]);
	}
	wk1(wk1,0,y);
	if(dp1[k]==dp2[k] and (mxn&1) and ((mxn+1)/2==dp1[k])){
		cout<<"Bob"<<endl;
	}else{
		cout<<"Alice"<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}