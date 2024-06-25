// Problem: D. Single-use Stones
// Contest: Codeforces - Codeforces Round 476 (Div. 2) [Thanks, Telegram!]
// URL: https://codeforces.com/problemset/problem/965/D
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

const int N=100010,M=18;

int a[N];

void solve(){
	int n,l;
	cin>>n>>l;
	for(int i=1;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		a[i]+=a[i-1];
	}
	int res=1e9;
	for(int i=0;i<n-l;i++){
		res=min(res,a[i+l]-a[i]);
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
