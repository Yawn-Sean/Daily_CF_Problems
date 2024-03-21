// Problem: B. New York Hotel
// Contest: Codeforces - Testing Round 11
// URL: https://codeforces.com/problemset/problem/491/B
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

const int N=100010,inf=1e18;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int ma_1=-inf,ma_2=-inf,ma_3=-inf,ma_4=-inf;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		ma_1=max(ma_1,x+y);
		ma_2=max(ma_2,x-y);
		ma_3=max(ma_3,y-x);
		ma_4=max(ma_4,-x-y);
	}
	int h;
	cin>>h;
	int len=inf,id;
	for(int i=1;i<=h;i++){
		int x,y;
		cin>>x>>y;
		int t=max(ma_1-x-y,max(ma_2-x+y,max(ma_3-y+x,ma_4+x+y)));
		if(t<len){
			len=t;
			id=i;
		}
	}
	cout<<len<<endl<<id<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
