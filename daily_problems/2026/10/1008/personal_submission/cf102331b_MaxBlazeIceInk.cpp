#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353
#define MAXN 300005
#define LOGN 62

int n,x,a[MAXN],son[MAXN * LOGN][2],edp[MAXN * LOGN],dp[MAXN];
int nodecnt,rt,highbit = 0;

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

void insert( int &t , int x , int k , int v ){
	if( !t ) t = ++nodecnt;
	if( k == -1 ){ chkadd( edp[t] , v ); return; }
	int ch = x >> k & 1;
	insert( son[t][ch] , x , k - 1 , v );
	edp[t] = ( edp[son[t][0]] + edp[son[t][1]] ) % mod;
}

int getc( int t , int k , int v ){
	if( !t ) return 0;
	if( k == -1 ) return 0;
	int ch = v >> k & 1;
	//我是唐诗
	if( x >> k & 1 ) return getc( son[t][ch ^ 1] , k - 1 , v );
	else return ( edp[son[t][ch ^ 1]] + getc( son[t][ch] , k - 1 , v ) ) % mod;
}

signed main(){
	scanf("%lld%lld",&n,&x);
	const int V = 60;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	if( x == 0 ){
		int ans = 1;
		for( int i = 1 ; i <= n ; i ++ ) ans = ans * 2 % mod;
		printf("%lld\n",( ans - 1 + mod ) % mod);
		return 0;
	}
	x --;
	sort( a + 1 , a + n + 1 );
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		dp[i] = 1;
		chkadd( dp[i] , getc( rt , V , a[i] ) );
		insert( rt , a[i] , V , dp[i] );
		chkadd( ans , dp[i] );
	}
	printf("%lld\n",ans);
	return 0;
}