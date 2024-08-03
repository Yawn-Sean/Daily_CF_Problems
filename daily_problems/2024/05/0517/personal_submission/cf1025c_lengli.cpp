// Problem: C. Plasticine zebra
// Contest: Codeforces - Codeforces Round 505 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)
// URL: https://codeforces.com/problemset/problem/1025/C
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

const int N=100010;

void solve(){
	string str;
	cin>>str;
	int n=str.size();
	str=str+str;
	
	int res=1;
	for(int i=1,j=1;i<n*2;i++){
		if(str[i-1]==str[i]) j=1;
		else j++;
		res=max(res,j);
	}
	res=min(res,n);
	cout<<res;
	
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
