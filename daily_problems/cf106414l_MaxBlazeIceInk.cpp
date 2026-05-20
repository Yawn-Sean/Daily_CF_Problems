#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define mod 1000000007

int n,a[MAXN],p[MAXN],pr[MAXN];

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline void solve(){
	scanf("%d",&n);
	for( int i = 0 ; i <= n ; i ++ ) pr[i] = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		int x,P,q; scanf("%d%d%d",&x,&P,&q);
		a[i] = x,p[i] = 1ll * P * fp( q , mod - 2 ) % mod;
		pr[x] = 1ll * pr[x] * ( mod + 1 - p[i] ) % mod;
	}
	for( int i = 0 ; i <= n ; i ++ ) pr[i] = mod + 1 - pr[i];
	int p = 1,ans = 0;
	for( int v = 0 ; v <= n ; v ++ ){
		p = 1ll * p * pr[v] % mod;
		chkadd( ans , 1ll * p % mod );
	}
	printf("%d\n",ans);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}