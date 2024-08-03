// Problem: D. Insert a Progression
// Contest: Codeforces - Educational Codeforces Round 127 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1671/D
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

const int N=100010;

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	int mi=2e9,ma=0,res=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
		if(i) res+=abs(a[i]-a[i-1]);
	}
	
	auto get=[&](int x){
		int ans=min(abs(a[0]-x),abs(a[n-1]-x));
		for(int i=1;i<n;i++){
			ans=min(ans,2*abs(a[i]-x));
		}
		return ans;
	};
	if(mi>1) res+=get(1);
	if(ma<x) res+=get(x);
	cout<<res<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
