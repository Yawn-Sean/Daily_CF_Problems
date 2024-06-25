// Problem: L. Longest Array Deconstruction
// Contest: Codeforces - COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1575/L
// Memory Limit: 512 MB
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

const int N=200010;

struct BIT{
	int n=N-1;
	int a[N];
	int lowbit(int x){return x&-x;}
	void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]=max(a[i],c);}
	
	void init(){
		
	};
	
	long long sum(int x){
		long long res=0;
		for(int i=x;i;i-=lowbit(i)) res=max(a[i],res);
		return res;
	}
	
}tr;

void solve(){
	int n;
	cin>>n;
	vector<array<int,2>> a(n+2);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]={i,x};
	}
	sort(a.begin()+1,a.begin()+1+n,[&](auto l,auto r){
		int ll=l[0]-l[1],rr=r[0]-r[1];
		if(ll!=rr) return ll<rr;
		return l[0]<r[0];
	});

	long long res=0;
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][0]) continue;
		int len=tr.sum(a[i][1]-1)+1;
		tr.add(a[i][1],len);
		res=max(res,len);
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
