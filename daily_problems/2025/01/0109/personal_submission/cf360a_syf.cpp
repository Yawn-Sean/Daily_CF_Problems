// Problem: A. Levko and Array Recovery
// Contest: Codeforces - Codeforces Round 210 (Div. 1)
// URL: https://codeforces.com/problemset/problem/360/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-09 21:00:54
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf=1e9;

void solve(){
	
	int n,m;cin>>n>>m;
	vector<vector<int>> a(m,vector<int>(4));
	vector<int> b(n),ans(n,inf);
	for(int i=0;i<m;i++){
		int op,l,r,d;cin>>op>>l>>r>>d;
		a[i]={op,l,r,d};
		if(op==1){
			for(int j=l-1;j<r;j++) b[j]+=d;
		}else{
			for(int j=l-1;j<r;j++){
				ans[j]=min(ans[j],d-b[j]);
			}
		}
	}
	auto tmp=ans;
	for(int i=0;i<m;i++){
		int op=a[i][0],l=a[i][1],r=a[i][2],d=a[i][3];
		if(op==1){
			for(int j=l-1;j<r;j++){
				tmp[j]+=d;
			}
		}else{
			int mx=-inf;
			for(int j=l-1;j<r;j++){
				mx=max(mx,tmp[j]);
			}
			if(mx!=d){
				cout<<"NO";
				return;
			}
		}
	}
	cout<<"YES\n";
	for(int x:ans)cout<<x<<" ";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
