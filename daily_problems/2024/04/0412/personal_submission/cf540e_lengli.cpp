// Problem: E. Infinite Inversions
// Contest: Codeforces - Codeforces Round 301 (Div. 2)
// URL: https://codeforces.com/problemset/problem/540/E
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

const int N=400010;

struct BIT{
	int n=N-1;
	int a[N];
	int lowbit(int x){return x&-x;}
	void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
	
	long long sum(int x){
		long long res=0;
		for(int i=x;i;i-=lowbit(i)) res+=a[i];
		return res;
	}
	
}tr;

void solve(){
	int n;
	cin>>n;
	vector<int> q;
	vector<array<int,2>> op;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		op.pb({l,r});
		q.pb(l),q.pb(r);
	}
	sort(all(q));
	q.erase(unique(all(q)),q.end());
	vector<array<int,2>> a;
	for(int i=0,j=1;i<q.size();i++){
		int t=q[i]-1;
		if(j<=t){
			a.pb({j,t-j+1});
		}
		a.pb({q[i],1});
		j=q[i]+1;
	}
	q.clear();
	for(auto [x,len]:a) q.pb(x);
	sort(all(q));
	q.erase(unique(all(q)),q.end());
	auto get=[&](int x){
		return lower_bound(all(q),x)-q.begin()+1;
	};
	for(auto [l,r]:op){
		l=get(l)-1,r=get(r)-1;
		swap(a[l],a[r]);
	}
	debug(a);
	
	long long res=0;
	reverse(all(a));
	
	for(auto [x,len]:a){
		x=get(x);
		res+=tr.sum(x)*len;
		tr.add(x,len);
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
