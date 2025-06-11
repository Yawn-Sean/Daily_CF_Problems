// Problem: B. Good Triple
// Contest: Codeforces - Codeforces Round 562 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1168/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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
	string s;
	cin>>s;
	int res=0;
	int n=s.size();
	int mi=n+1;
	for(int i=n;i>=1;i--){
		for(int j=1;i+j*2<=n;j++){
			if(s[i-1]==s[i+j-1] and s[i+j-1]==s[i+j*2-1]){
				mi=min(mi,i+2*j);
				break;
			}
		}
		res+=n-mi+1;
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
