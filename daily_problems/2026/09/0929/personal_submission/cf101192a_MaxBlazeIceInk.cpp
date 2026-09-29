#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define mod 1000000007

int n,a[MAXN],b[MAXN],A[MAXN],acnt,f[MAXN],v[MAXN],tr[MAXN];
vector<int> fac[MAXN],pos[MAXN];

const int V = 1000000;

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }
inline void add( int x , int k ){ for( ; x <= acnt ; x += x & -x ) chkadd( tr[x] , k ); };
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) chkadd( ret , tr[x] ); return ret; }
inline int reduce( int x ){ return x < 0 ? x + mod : x; }

signed main(){
	for( int i = 1 ; i <= V ; i ++ )
		for( int j = i ; j <= V ; j += i ) fac[j].emplace_back( i );
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),A[++acnt] = a[i];
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&b[i]);
	sort( A + 1 , A + acnt + 1 );
	acnt = unique( A + 1 , A + acnt + 1 ) - ( A + 1 );
	for( int i = 1 ; i <= n ; i ++ ) a[i] = lower_bound( A + 1 , A + acnt + 1 , a[i] ) - A;
	for( int i = 1 ; i <= n ; i ++ )
		for( int ele : fac[b[i]] ) pos[ele].emplace_back( i );
	
	int ans = 0;
	for( int g = V ; g >= 1 ; g -- ){
		for( int ele : pos[g] ){
			f[ele] = ( sum( a[ele] - 1 ) + 1 ) % mod;
			add( a[ele] , f[ele] );
		}
		v[g] = sum( acnt );
		for( int ele : pos[g] )
			add( a[ele] , reduce( mod - f[ele] ) );
		for( int gg = 2 * g ; gg <= V ; gg += g )
			v[g] = reduce( v[g] - v[gg] );
		chkadd( ans , 1ll * v[g] * g % mod );
	}
	printf("%d\n",ans);
	return 0;
}