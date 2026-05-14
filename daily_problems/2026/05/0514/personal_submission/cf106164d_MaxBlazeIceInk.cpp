#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define mod 998244353

int n,k,r,p[MAXN],f[MAXN],C[MAXN];
int minn[MAXN << 2];

void modify( int t , int l , int r , int x , int k ){
	if( l == r ){ minn[t] = k; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x , k );
	else modify( t << 1 | 1 , mid + 1 , r , x , k );
	minn[t] = min( minn[t << 1] , minn[t << 1 | 1] );
}

int query( int t , int l , int r , int L ){
	if( l == r ) return l;
	int mid = ( l + r ) >> 1;
	if( minn[t << 1] >= L ) return query( t << 1 | 1 , mid + 1 , r , L );
	else return query( t << 1 , l , mid , L );
}

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

struct matrix{
	int a[2][2];
	inline matrix(){ memset( a , 0 , sizeof( a ) ); }
	inline int* operator []( int x ){ return a[x]; }
	inline matrix operator *( matrix B ){
		matrix C;
		for( int i = 0 ; i < 2 ; i ++ )
			for( int j = 0 ; j < 2 ; j ++ )
				for( int k = 0 ; k < 2 ; k ++ )
					chkadd( C[i][j] , 1ll * a[i][k] * B[k][j] % mod );
		return C;
	}
};

inline matrix fpm( matrix x , int p ){
	matrix res; res[0][0] = res[1][1] = 1;
	while( p ){
		if( p & 1 ) res = res * x;
		x = x * x;
		p >>= 1;
	}
	return res;
}

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		p >>= 1;
	}
	return res;
}

void build( int t , int l , int r ){
	minn[t] = -1;
	if( l == r ) return;
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
}

inline int reduce( int x ){ return x < 0 ? x + mod : x; }

inline void fwt( int *f ){
	for( int i = 1 ; i < 1 << 19 ; i <<= 1 ){
		for( int j = 0 ; j < 1 << 19 ; j += i << 1 ){
			for( int k = 0 ; k < i ; k ++ ){
				int X = f[j + k],Y = f[i + j + k];
				f[j + k] = ( X + Y ) % mod,f[i + j + k] = ( X - Y + mod ) % mod;
			}
		}
	}
}

signed main(){
	scanf("%d%d%d",&n,&k,&r);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&p[i]);
	build( 1 , 0 , n + 1 );
	f[0] = 0,C[0] ++;
	modify( 1 , 0 , n + 1 , 0 , 0 );
	for( int i = 1 ; i <= n ; i ++ ){
		int mex = query( 1 , 0 , n + 1 , i - p[i] );
		f[i] = mex,C[mex] ++;
		modify( 1 , 0 , n + 1 , mex , i );
	}
	// for( int i = 1 ; i <= n ; i ++ ) cerr << f[i] << " ";
	fwt( C );
	for( int i = 0 ; i < 1 << 19 ; i ++ ) C[i] = 1ll * fp( C[i] , r ) % mod;
	for( int i = 1 ; i < 1 << 19 ; i ++ ) chkadd( C[0] , C[i] );
	for( int i = 0 ; i < 19 ; i ++ ) C[0] = 1ll * C[0] * 499122177 % mod;
	int X = C[0];
	memset( C , 0 , sizeof( C ) );
	for( int i = 0 ; i <= n ; i ++ ){
		if( i + k > n || f[i] == f[i + k] )
			C[f[i]] ++;
	}
	fwt( C );
	for( int i = 0 ; i < 1 << 19 ; i ++ ) C[i] = 1ll * fp( C[i] , r ) % mod;
	for( int i = 1 ; i < 1 << 19 ; i ++ ) chkadd( C[0] , C[i] );
	for( int i = 0 ; i < 19 ; i ++ ) C[0] = 1ll * C[0] * 499122177 % mod;
	int Y = C[0];
	int ans = reduce( X - Y );
	printf("%d\n",ans);
	return 0;
}