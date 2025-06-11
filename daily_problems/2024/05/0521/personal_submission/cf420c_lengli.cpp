// Problem: C. Bug in Code
// Contest: Codeforces - Coder-Strike 2014 - Finals (online edition, Div. 1)
// URL: https://codeforces.com/problemset/problem/420/C
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

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=300010;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> cnt(n,0);
	map<array<int,2>,int> q;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		cnt[x]++,cnt[y]++;
		if(x>y) swap(x,y);
		q[{x,y}]++;
	}
	
	long long res=0;
	for(auto [t,v]:q)
		if(cnt[t[0]]+cnt[t[1]]-v<k and cnt[t[0]]+cnt[t[1]]>=k) res--;
	sort(all(cnt));
	for(int i=0;i<n;i++){
		res+=n-(lower_bound(cnt.begin()+i+1,cnt.end(),k-cnt[i])-cnt.begin());
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
