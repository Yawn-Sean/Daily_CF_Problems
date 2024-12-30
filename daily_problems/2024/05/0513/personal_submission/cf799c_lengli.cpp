// Problem: C. Fountains
// Contest: Codeforces - Playrix Codescapes Cup (Codeforces Round 413, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/799/C
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

const int N=100010;

struct BIT{
	int n=N-1;
	int a[N];
	int lowbit(int x){return x&-x;}
	void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]=max(a[i],c);}
	
	int sum(int x){
		int res=0;
		for(int i=x;i;i-=lowbit(i)) res=max(a[i],res);
		return res;
	}
	
}tr;

void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<array<int,2>> l,r;
	for(int i=0;i<n;i++){
		int b,p;
		cin>>b>>p;
		char c;
		cin>>c;
		if(c=='C') l.pb({b,p});
		else r.pb({b,p});
	}
	sort(all(l),[&](auto ll,auto rr){
		return ll[1]<rr[1];
	});
	int res=0;
	vector<int> ans;
	for(auto [v,p]:l){
		if(p<a and tr.sum(a-p)) res=max(res,tr.sum(a-p)+v);
		tr.add(p,v);
	}
	if(tr.sum(a)) ans.pb(tr.sum(a));
	sort(all(r),[&](auto ll,auto rr){
		return ll[1]<rr[1];
	});
	for(int i=0;i<=b;i++) tr.a[i]=0;
	for(auto [v,p]:r){
		if(p<b and tr.sum(b-p)) res=max(res,tr.sum(b-p)+v);
		tr.add(p,v);
	}
	if(tr.sum(b)) ans.pb(tr.sum(b));
	if(ans.size()==2){
		res=max(res,ans[0]+ans[1]);
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
