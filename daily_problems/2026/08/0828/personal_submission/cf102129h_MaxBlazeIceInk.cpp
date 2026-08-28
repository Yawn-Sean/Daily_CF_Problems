#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int m;

inline int sqrt_root( int X ){
	int t = sqrtl( X ) + 4;
	while( t * t > X ) t --;
	return t;
}

inline int inv( int x ){
	int res = 1,p = mod - 2;
	while( p ){
		if( p & 1 ) res = res * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return res;
}

inline void solve(){
	scanf("%lld",&m);
	if( m == 3 ){ puts("1"); return; }
	int v = ( 2 * m + 1 - sqrt_root( 2 * m * m + 2 * m + 1 ) ) / 2; //求根公式底下是 2a
	// cerr << v << "\n";
	//这是下取整，实际上我们就可以得到真正的一次方程，并且一定有有理数解
	for( int k = v - 1 ; k <= v ; k ++ ){
		if( m == k ) continue;
		int A = m * ( m + 1 ) - 2 * k * ( k + 1 );
		int B = 4 * ( m - k );
		if( A / B == k ){
			A %= mod,B %= mod;
			printf("%lld\n",A * inv( B ) % mod);
			return;
		}
	}
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}