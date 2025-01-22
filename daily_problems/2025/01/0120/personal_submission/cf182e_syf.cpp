// Problem: E. Wooden Fence
// Contest: Codeforces - Codeforces Round 117 (Div. 2)
// URL: https://codeforces.com/problemset/problem/182/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// DateTime : 2025-01-20 20:00:19
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod=1e9+7;

void solve(){
	int n,l;cin>>n>>l;
	vector<array<int,2>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	vector<vector<int>> f(2*n+1,vector<int>(l+1));
	f[2*n][0]=1;
	for(int i=0;i<=l;i++){
		for(int j=0;j<=2*n;j++){
			for(int k=0;k<n;k++){
				if(k!=j/2){
					int len=(j==2*n?0:a[j/2][j%2]);
					if((len==0||a[k][0]==len)&&i+a[k][0]<=l){
						f[2*k+1][i+a[k][0]]+=f[j][i];
						f[2*k+1][i+a[k][0]]%=mod;
					}
					if(a[k][0]!=a[k][1]&&(len==0||a[k][1]==len)&&i+a[k][1]<=l){
						f[2*k][i+a[k][1]]+=f[j][i];
						f[2*k][i+a[k][1]]%=mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=2*n;i++){
		ans=(ans+f[i][l])%mod;
	}
	cout<<ans;
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
