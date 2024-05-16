// Problem: C. Subsequence Counting
// Contest: Codeforces - Divide by Zero 2018 and Codeforces Round 474 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/960/C
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
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int s,k;
	cin>>s>>k;
	vector<int> res;
	
	int la=-1e9;
	
	while(s){
		la=la+1e9+1;
		for(int j=1;j<=32;j++){
			if((1ll<<j)-1<s) continue;
			if((1ll<<j)-1>s) j--;
			for(int t=0;t<j;t++) res.pb(la);
			s-=(1ll<<j)-1;
			break;
		}
	}
	cout<<res.size()<<endl;
	for(auto x:res) cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
