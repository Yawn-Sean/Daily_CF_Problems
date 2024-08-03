// Problem: C. Crazy Diamond
// Contest: Codeforces - Codeforces Global Round 3
// URL: https://codeforces.com/problemset/problem/1148/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1);
	
	vector<int> b(n+1);
	
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	
	vector<array<int,2>> res;
	
	auto cal=[&](int l,int r){
		if(l>r) swap(l,r);
		if(r-l>=n/2){
			res.pb({l,r});
			return;
		}
		if(r<=n/2){
			res.pb({l,n});
			res.pb({r,n});
			res.pb({l,n});
		}else if(l>n/2){
			res.pb({l,1});
			res.pb({r,1});
			res.pb({l,1});
		}else{
			res.pb({r,1});
			res.pb({1,n});
			res.pb({r,1});
			res.pb({l,n});
			res.pb({n,1});
			res.pb({r,1});
			res.pb({1,n});
		}
	};
	
	for(int i=1,j=n;i<=n/2;i++){
		if(a[i]>n/2){
			while(j>n/2 and a[j]>n/2) j--;
			cal(i,j);
			swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		debug(a);
		while(a[i]!=i){
			cal(i,a[i]);
			swap(a[i],a[a[i]]);
		}
		debug(a);
	}
	cout<<res.size()<<endl;
	for(auto [l,r]:res) {
		swap(b[l],b[r]);
		cout<<l<<" "<<r<<endl;
	}
	debug(b);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
