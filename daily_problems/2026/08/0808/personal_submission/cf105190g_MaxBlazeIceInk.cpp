#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

int n,p0,q0,p1,q1,p2,q2;

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

struct matrix{
	int a[3][3];
	matrix(){ memset( a , 0 , sizeof( a ) ); }
	inline int* operator []( int x ){ return a[x]; }
	inline matrix operator *( matrix B ){
		matrix C;
		for( int i = 0 ; i < 3 ; i ++ )
			for( int j = 0 ; j < 3 ; j ++ )
				for( int k = 0 ; k < 3 ; k ++ )
					chkadd( C[i][j] , a[i][k] * B[k][j] % mod );
		return C;
	}
};

inline matrix fpm( matrix B , int p ){
	matrix res; res[0][0] = res[1][1] = res[2][2] = 1;
	while( p ){
		if( p & 1 ) res = res * B;
		B = B * B;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&p0,&q0,&p2,&q2,&p1,&q1);
	p0 = p0 * fp( q0 , mod - 2 ) % mod;
	p1 = p1 * fp( q1 , mod - 2 ) % mod;
	p2 = p2 * fp( q2 , mod - 2 ) % mod;
	matrix R;
	R[0][0] = mod + 1 - p1,R[0][1] = mod + 1 - p2;
	R[1][0] = R[2][0] = p1,R[1][1] = R[2][1] = p2;
	R[2][2] = 1;
	matrix P; P[0][2] = 1;
	P = P * fpm( R , n - 1 );
	int ans = P[0][0] * ( mod + 1 - p0 ) % mod;
	chkadd( ans , ( P[0][1] + 1 ) * p0 % mod );
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}