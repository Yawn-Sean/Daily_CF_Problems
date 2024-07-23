// Problem: B. Nauuo and Circle
// Contest: Codeforces - Codeforces Round 564 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1172/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
using namespace std;
const  int md=998244353;
using LL=long long;

void solve(){
	int n;cin>>n;
	vector<LL>deg(n+1);
	LL ans=1;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		deg[a]++,deg[b]++;
		ans=ans*deg[a]*deg[b]%md;
	}
	
	cout<<1LL*ans*n%md<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
