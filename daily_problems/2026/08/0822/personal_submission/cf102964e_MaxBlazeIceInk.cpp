#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define mod 1000000007

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

inline int inv( int x ){ return fp( x , mod - 2 ); }

int n,x,k,a[MAXN];

signed main(){
	scanf("%d%d%d",&n,&x,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	if( !k ){
		int c = 0;
		for( int i = 1 ; i < n ; i ++ ) c += a[i] != a[i + 1];
		printf("%d\n",c + 1); return 0;
	}
	int dif = 1ll * ( x - 1 ) * inv( x ) % mod;
	int c = ( fp( 2 , k ) - 1 + mod ) % mod;
	int ans = 1ll * dif * ( c - 1 + mod ) % mod * ( n - 1 ) % mod;
	ans = ( ans + 1ll * dif * ( 2 * n - 2 ) % mod ) % mod;
	printf("%d\n",( ans + 1 ) % mod);
	return 0;
}