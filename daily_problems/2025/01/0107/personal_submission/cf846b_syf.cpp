// Problem: B. Math Show
// Contest: Codeforces - Educational Codeforces Round 28
// URL: https://codeforces.com/problemset/problem/846/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-07 16:52:06
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,k,M;cin>>n>>k>>M;
	int sum=0;
	vector<int> a(k);
	for(int&x:a)cin>>x,sum+=x;
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=0;i<=min(n,M/sum);i++){
		int m=M,res=0;
		m-=sum*i;
		res+=i*(k+1);
		for(int x:a){
			if(m>=(n-i)*x){
				res+=n-i;
				m-=(n-i)*x;
			}else{
				res+=m/x;
				break;
			}
		}
		ans=max(ans,res);
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
