#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define pmod 1000000006
#define MAXN 55

int n,k,f[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= pmod ) x -= pmod; }

struct matrix{
	int a[MAXN][MAXN];
	matrix(){ memset( a , 0 , sizeof( a ) ); }
	inline int* operator []( int x ){ return a[x]; }
	inline matrix operator *( matrix B ){
		matrix C;
		for( int i = 0 ; i < n ; i ++ )
			for( int j = 0 ; j < n ; j ++ )
				for( int k = 0 ; k < n ; k ++ )
					chkadd( C[i][j] , a[i][k] * B[k][j] % pmod );
		return C;
	}
};

inline matrix fpm( matrix A , int p ){
	matrix res;
	for( int i = 0 ; i < n ; i ++ ) res[i][i] = 1;
	while( p ){
		if( p & 1 ) res = res * A;
		A = A * A;
		p >>= 1;
	}
	return res;
}

inline int fp( int x , int p ){
	int res = 1;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

signed main(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&f[i]);
	if( k <= n ) printf("%lld\n",f[k]);
	else{
		matrix R;
		for( int i = 0 ; i < n ; i ++ ) R[i][0] = f[i + 1];
		for( int i = 0 ; i < n - 1 ; i ++ ) R[i][i + 1] = 1;
		matrix tmp = fpm( R , k - n );
		int res = 1;
		for( int i = 0 ; i < n ; i ++ ){
			matrix S; S[0][n - i - 1] = 1;
			S = S * tmp;
			// cerr << i << " " << S[0][0] << "\n";
			res = res * fp( f[i + 1] , S[0][0] ) % mod;
		}
		printf("%lld\n",res);
	}
	return 0;
}