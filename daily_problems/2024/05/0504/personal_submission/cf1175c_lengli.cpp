// Problem: C. Electrification
// Contest: Codeforces - Educational Codeforces Round 66 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1175/C
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

void solve(){
	int n,k;
	cin>>n>>k;k++;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	a.pb(2e9);
	sort(all(a));
	int l=0,r=1e9;
	debug(a);
	auto check=[&](int len){
		for(int i=0;i<n;i++){
			auto idx=upper_bound(all(a),a[i]+2*len)-a.begin()-1;
			if(idx-i+1>=k) return 1;
		}
		return 0;
	};

	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	for(int i=0;i<n;i++){
		auto idx=upper_bound(all(a),a[i]+2*r)-a.begin()-1;
		if(idx-i+1>=k) {
			cout<<a[i]+r<<endl;
			return;
		}
	}
	
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
