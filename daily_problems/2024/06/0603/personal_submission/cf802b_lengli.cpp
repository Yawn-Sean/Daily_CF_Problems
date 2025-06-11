// Problem: A. Heidi and Library (easy)
// Contest: Codeforces - Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL: https://codeforces.com/contest/802/problem/A
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

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010,inf=1e9;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+2),cnt(n+2,0),ne(n+2,inf);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=n;i>=1;i--){
		if(cnt[a[i]]) ne[i]=cnt[a[i]];
		cnt[a[i]]=i;
	}
	vector<int> st(n+2);
	set<array<int,2>,greater<>> s;
	int res=0;
	for(int i=1;i<=n;i++){
		if(st[a[i]]) {
			s.erase(s.find({i,a[i]}));
			s.insert({ne[i],a[i]});
			continue;
		}
		while(s.size()>=k){
			auto t=*s.begin();
			s.erase(t);
			st[t[1]]=0;
		}
		res++;
		st[a[i]]=1;
		s.insert({ne[i],a[i]});
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
