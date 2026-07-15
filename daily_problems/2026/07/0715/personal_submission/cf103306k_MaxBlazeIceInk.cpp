#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define mod 1000000007

int notp[MAXN],prime[MAXN],ptot,mu[MAXN],n,f[MAXN],p2[MAXN];

inline int reduce( int x ){ return x < 0 ? x + mod : x; }
inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

inline void Euler(){
	notp[1] = 1,mu[1] = 1;
	for( int i = 2 ; i < MAXN ; i ++ ){
		if( !notp[i] ) prime[++ptot] = i,mu[i] = mod - 1;
		for( int j = 1 ; j <= ptot && i * prime[j] < MAXN ; j ++ ){
			notp[i * prime[j]] = 1;
			if( i % prime[j] == 0 ) break;
			mu[i * prime[j]] = mod - mu[i];
		}
	}
	for( int i = 1 ; i < MAXN ; i ++ ){
		chkadd( f[i] , p2[i] );
		for( int j = i * 2 ; j < MAXN ; j += i )
			chkadd( f[j] , ( mod - f[i] ) % mod );
	}
}

inline void solve(){
	int K; scanf("%lld",&K);
	printf("%lld\n",( p2[K] - f[K] + mod ) % mod);
}

signed main(){
	p2[0] = 1; for( int i = 1 ; i < MAXN ; i ++ ) p2[i] = p2[i - 1] * 2 % mod;
	Euler();
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}