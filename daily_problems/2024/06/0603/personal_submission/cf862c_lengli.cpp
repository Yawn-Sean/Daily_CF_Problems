// Problem: C. Mahmoud and Ehab and the xor
// Contest: Codeforces - Codeforces Round 435 (Div. 2)
// URL: https://codeforces.com/problemset/problem/862/C
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
	
	if(n==2 and x==0){
		cout<<"NO"<<endl;
		return;
	}
	
	vector<int> q;
	q.pb(0),q.pb(3);
	while(q.back()<=1000000) q.pb({q.back()+4});
	int k=(n/4)*4;
	n%=4;
	if(!n) n+=4,k-=4;
	vector<int> res;
	auto st=lower_bound(all(q),200000)-q.begin();
	for(int i=q[st]+1,j=k;j>0;j--,i++) {
		res.pb(i);
	}
	
	
	if(n==1) res.pb(x);
	else if(n==2){
		if(x) res.pb(0),res.pb(x);
		else res.back()+=524288,res.pb(0),res.pb(x+524288);
	}else if(n==3){
		if(x!=65536) res.pb(65536),res.pb(589824),res.pb(524288+x);
		else res.pb(32768),res.pb(557056),res.pb(524288+x);
	}else{
		res.pb(0);
		if(x!=65536) res.pb(65536),res.pb(589824),res.pb(524288+x);
		else res.pb(32768),res.pb(557056),res.pb(524288+x);
	}
	cout<<"YES"<<endl;
	int ans=0;
	for(auto x:res) {
		cout<<x<<" ";
		ans^=x;
	}
	assert(ans==x);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
