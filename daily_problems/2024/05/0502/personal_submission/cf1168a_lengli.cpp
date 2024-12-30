// Problem: A. Increasing by Modulo
// Contest: Codeforces - Codeforces Round 562 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1168/A
// Memory Limit: 256 MB
// Time Limit: 2500 ms

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
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	
	auto check=[&](int x){
		int la=(a[0]+x>=m ? 0 : a[0]);
		for(int i=1;i<n;i++){
			if(a[i]==la) continue;
			if(a[i]>la) {
				if(a[i]+x>=m and (a[i]+x)%m>=la) continue;
				else la=a[i];
			}else{
				int d=la-a[i];
				if(x<d) return 0;
			}
			
		}
		return 1;
	};
	int l=0,r=1e9;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<r;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
