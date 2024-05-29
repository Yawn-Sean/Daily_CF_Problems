// Problem: D. Gadgets for dollars and pounds
// Contest: Codeforces - Educational Codeforces Round 3
// URL: https://codeforces.com/problemset/problem/609/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

const int N=100010,inf=2e9;

void solve(){
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	
	vector<int> a(n+2),b(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	vector<array<int,2>> tool(m+2);
	for(int i=1;i<=m;i++) cin>>tool[i][0]>>tool[i][1];
	
	int l=1,r=n;
	int c1=1,c2=1;
	vector<array<int,2>> q;
	auto check=[&](int d)->bool{
		c1=1,c2=1;
		for(int i=1;i<=d;i++) if(a[i]<a[c1]) c1=i; 
		for(int i=1;i<=d;i++) if(b[i]<b[c2]) c2=i; 
		q.clear();
		for(int i=1;i<=m;i++){
			q.pb({tool[i][0]==1 ? tool[i][1]*a[c1] : tool[i][1]*b[c2],i});
		}
		sort(all(q));
		if(q.size()<k) return 0;
		long long sum=0;
		for(int i=0;i<k;i++) sum+=q[i][0];
		return sum<=(long long)s;	
	};
	
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(check(r)){
		cout<<r<<endl;
		for(int i=0;i<k;i++){
			auto id=q[i][1];
			if(tool[id][0]==1) cout<<id<<" "<<c1<<endl;
			else cout<<id<<" "<<c2<<endl;
		}
	}else cout<<-1<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
