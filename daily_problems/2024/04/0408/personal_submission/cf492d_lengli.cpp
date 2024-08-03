// Problem: D. Vanya and Computer Game
// Contest: Codeforces - Codeforces Round 280 (Div. 2)
// URL: https://codeforces.com/problemset/problem/492/D
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
	int n,x,y;
	cin>>n>>x>>y;
	int d=lcm(x,y);
	x=d/x,y=d/y;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		
		int l=0,r=1e18;
		
		while(l<r){
			int mid=(l+r)/2;
			if(mid/x+mid/y>=k) r=mid;
			else l=mid+1;
		}
		if(r%x==0 and r%y==0) cout<<"Both"<<endl;
		else if(r%x==0) cout<<"Vanya"<<endl;
		else cout<<"Vova"<<endl;
	}
}

signed main(){
    fastio;
     
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
