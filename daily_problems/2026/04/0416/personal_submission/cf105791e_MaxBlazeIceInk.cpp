//\sum p * (1-p) = \prod(1-p) * \sum p/(1-p)
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
#define MAXN 200005

int n,q,p[MAXN],tr[MAXN],tr2[MAXN];

inline void mul( int x , int k ){ for( ; x ; x -= x & -x ) tr[x] = tr[x] * k % mod; }
inline int prod( int x ){ int ret = 1; for( ; x <= n + 1 ; x += x & -x ) ret = ret * tr[x] % mod; return ret; }
inline void add( int x , int k ){ for( ; x ; x -= x & -x ) tr2[x] = ( tr2[x] + k ) % mod; }
inline int sum( int x ){ int ret = 0; for( ; x <= n + 1 ; x += x & -x ) ret = ( ret + tr2[x] ) % mod; return ret; }

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
	scanf("%lld%lld",&n,&q);
	for( int i = 1 ; i <= n + 1 ; i ++ ) tr[i] = 1;
	int i100 = fp( 100 , mod - 2 );
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&p[i]);
		p[i] = p[i] * i100 % mod;
		mul( i , ( mod + 1 - p[i] ) % mod );
		add( i , p[i] * fp( mod + 1 - p[i] , mod - 2 ) % mod );
	}
	// cerr << prod( 3 ) << "\n";
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%lld",&op);
		if( op == 1 ){
		int id,np; scanf("%lld%lld",&id,&np);
		mul( id , fp( ( mod + 1 - p[id] ) , mod - 2 ) );
		add( id , mod - ( p[id] * fp( mod + 1 - p[id] , mod - 2 ) % mod ) );
		p[id] = np * i100 % mod;
		mul( id , ( mod + 1 - p[id] ) % mod );
		add( id , p[id] * fp( mod + 1 - p[id] , mod - 2 ) % mod );
		}
		else{
		int id; scanf("%lld",&id);
		// cerr << prod( id + 1 ) << "\n";
		int p1 = prod( id + 1 ) * sum( id + 1 ) % mod;
		int p2 = prod( id + 1 );
		printf("%lld\n",( p1 + p2 ) % mod);
		}
	}
	return 0;
}