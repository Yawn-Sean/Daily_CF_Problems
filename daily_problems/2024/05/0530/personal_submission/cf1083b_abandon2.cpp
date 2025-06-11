// Problem: B. The Fair Nut and Strings
// Contest: Codeforces - Codeforces Round 526 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1083/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n,k;cin>>n>>k;
	string a,b;
	cin>>a>>b;a=' '+a;b=' '+b;
	int ans=0,c=1;
	for(int i=1;i<=n;i++){
		c*=2;
		if(a[i]=='b')c--;
		if(b[i]=='a')c--;
		if(c>=k){
			ans+=k*(n-i+1);
			break;
		}
		ans+=c;
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
