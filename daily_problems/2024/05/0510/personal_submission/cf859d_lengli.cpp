// Problem: D. Third Month Insanity
// Contest: Codeforces - MemSQL Start[c]UP 3.0 - Round 1
// URL: https://codeforces.com/contest/859/problem/D
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

const int N=1<<10;

int n;
double g[N][N];
double w[N][N],f[N][N];

void dfs(int u,int l,int r,int c){
	if(l==r){
		w[u][l]=1.0;
		f[u][l]=c;
		return;
	}
	int mid=(l+r)/2;
	dfs(u*2,l,mid,c/2);
	dfs(u*2+1,mid+1,r,c/2);
	
	for(int i=l;i<=mid;i++){
		for(int j=mid+1;j<=r;j++){
			w[u][i]+=w[u*2][i]*w[u*2+1][j]*g[i][j];
		}
	}
	for(int i=mid+1;i<=r;i++){
		for(int j=l;j<=mid;j++){
			w[u][i]+=w[u*2+1][i]*w[u*2][j]*g[i][j];
		}
	}
	
	for(int i=l;i<=mid;i++){
		for(int j=mid+1;j<=r;j++){
			f[u][i]=max(f[u][i],w[u][i]*c+f[u*2][i]+f[u*2+1][j]);
		}
	}
	for(int i=mid+1;i<=r;i++){
		for(int j=l;j<=mid;j++){
			f[u][i]=max(f[u][i],w[u][i]*c+f[u*2+1][i]+f[u*2][j]);
		}
	}
}

void solve(){
	cin>>n;
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j<=(1<<n);j++){
			int x;
			cin>>x;
			g[i][j]=(double)x/100.0;
		}
	}
	dfs(1,1,(1<<n),(1<<n)/2);
	
	double res=0;
	for(int i=1;i<=(1<<n);i++) res=max(res,f[1][i]);
	cout<<fixed<<setprecision(10)<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
