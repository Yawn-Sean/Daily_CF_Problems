// Problem: E. Correcting Mistakes
// Contest: Codeforces - VK Cup 2015 - Round 2 (unofficial online mirror, Div. 1 only)
// URL: https://codeforces.com/problemset/problem/533/E
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
	int n;
	string a,b;
	cin>>n>>a>>b;
	vector<int> q;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			while(q.size() and i!=q.back()+1) q.pb(q.back()+1);
			q.pb(i);
		}
	}
	if(q.size()==1) cout<<2<<endl;
	else{
		auto check=[&](int t){
			char c=t ? a[q[0]] : b[q[0]];
			for(int i=1;i<q.size();i++){
				int id=q[i];
				if(!t and a[id]==c) t=0,c=b[id];
				else if(t and b[id]==c) t=1,c=a[id];
				else t=-1;
				if(t==-1) return 0;
			}
			return 1;
		};
		
		auto l=check(0),r=check(1);
		if(check(l) and check(r)) cout<<2<<endl;
		else if(check(l) or check(r)) cout<<1<<endl;
		else cout<<0<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
