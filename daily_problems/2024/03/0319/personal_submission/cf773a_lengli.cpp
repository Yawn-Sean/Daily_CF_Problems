// Problem: A. Success Rate
// Contest: Codeforces - VK Cup 2017 - Round 3
// URL: https://codeforces.com/problemset/problem/773/A
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
	int x,y,p,q;
	cin>>x>>y>>p>>q;
	if(!p) {
		cout<<(!x ? 0 : -1)<<endl;
		return;
	}
	if(p==q){
		cout<<(x==y ? 0 : -1)<<endl;
		return;
	}
	int r1=(x+p-1)/p;
	int r2=(y-x+q-p-1)/(q-p);
	cout<<q*max(r1,r2)-y<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
