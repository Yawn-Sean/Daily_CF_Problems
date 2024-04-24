// Problem: C. Hongcow Buys a Deck of Cards
// Contest: Codeforces - Codeforces Round 385 (Div. 1)
// URL: https://codeforces.com/contest/744/problem/C
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

const int N=100010,inf=1e9;

void solve(){
	int n;
	cin>>n;
	vector<char> c(n);
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++) cin>>c[i]>>x[i]>>y[i];
	vector<vector<int>> f((1<<n),vector<int>(130,-inf));
	f[0][0]=0;
	
	for(int i=0;i<(1<<n);i++){
		int R=0,B=0;
		for(int j=0;j<n;j++){
			if(i>>j&1) {
				if(c[j]=='R') R++;
				else B++;
			}
		}
		for(int j=0;j<n;j++){
			if(i>>j&1) continue;
			for(int k=0;k<=120;k++){
				if(f[i][k]!=-inf){
					f[i^(1<<j)][k+min(x[j],R)]=max(f[i^(1<<j)][k+min(x[j],R)],f[i][k]+min(y[j],B));
				}
			}
		}
	}
	
	int res=inf,l=0,r=0;
	for(int i=0;i<n;i++) l+=x[i],r+=y[i];
	for(int i=0;i<=120;i++) res=min(res,max(l-i,r-f[(1<<n)-1][i]));
	cout<<res+n;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
