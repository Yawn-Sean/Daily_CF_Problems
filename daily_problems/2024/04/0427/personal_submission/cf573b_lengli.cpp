// Problem: B. Bear and Blocks
// Contest: Codeforces - Codeforces Round 318 [RussianCodeCup Thanks-Round] (Div. 1)
// URL: https://codeforces.com/problemset/problem/573/B
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
	int n;
	cin>>n;
	
	vector<int> a(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	
	vector<int> l(n+2,0),r(n+2,0);
	auto check=[&](int x){
		for(int i=1;i<=n;i++){
			int la=l[i-1];
			if(a[i]>la) l[i]=l[i-1]+1;
			else l[i]=min(a[i],l[i-1]);
		}
		for(int i=n;i>=1;i--){
			int la=r[i+1];
			if(a[i]>la) r[i]=r[i+1]+1;
			else r[i]=min(a[i],r[i+1]);
		}
		for(int i=1;i<=n;i++){
			if(r[i]>=x and l[i]>=x) return 1;
		}
		return 0;
	};
	int L=0,R=1e9;
	while(L<R){
		int mid=(L+R+1)/2;
		if(check(mid)) L=mid;
		else R=mid-1;
	}
	cout<<L;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
