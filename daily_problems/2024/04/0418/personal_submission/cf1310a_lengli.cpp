// Problem: A. Recommendations
// Contest: Codeforces - VK Cup 2019-2020 - Elimination Round (Engine)
// URL: https://codeforces.com/problemset/problem/1310/A
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

const int N=100010;

void solve(){
	int n;
	cin>>n;
	vector<array<int,2>> q(n);
	for(int i=0;i<n;i++) cin>>q[i][0];
	for(int i=0;i<n;i++) cin>>q[i][1];
	
	sort(all(q));
	set<int> s;
	int la=0;
	for(auto [x,v]:q){
		la=max(la+1,x);
		s.insert(la);
	}
	sort(all(q),[&](auto l,auto r){
		return l[1]>r[1];
	});
	int res=0;
	for(auto [x,v]:q){
		auto it=s.lower_bound(x);
		res+=((*it)-x)*v;
		s.erase(it);
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
