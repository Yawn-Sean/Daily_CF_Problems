// Problem: A. Golden System
// Contest: Codeforces - MemSQL Start[c]UP 2.0 - Round 2
// URL: https://codeforces.com/problemset/problem/457/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
 
/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif
 
const int N=100010;
 
void solve(){
	string a,b;
	cin>>a>>b;
	reverse(all(a)),reverse(all(b));
	int n=a.size(),m=b.size();
	vector<int> f(N,0);
	vector<int> g(N,0);
	for(int i=1;i<=n;i++) if(a[i-1]=='1') f[i]=1;
	for(int i=1;i<=m;i++) if(b[i-1]=='1') g[i]=1;
	for(int i=N-1;i>=3;i--){
		if(f[i-1]==1 and f[i-2]==1 and f[i]==0) f[i]=1,f[i-1]=0,f[i-2]=0,i+=3;
		if(g[i-1]==1 and g[i-2]==1 and g[i]==0) g[i]=1,g[i-1]=0,g[i-2]=0,i+=3;
	}
	int flag=0;
	for(int i=N-1;i>=1 and !flag;i--){
		if(f[i]!=g[i]){
			if(f[i]==1) flag=1;
			else flag=-1;
		} 
	}
	cout<<(!flag ? "=" : flag==-1 ? "<" : ">"); 
}	
 
signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
