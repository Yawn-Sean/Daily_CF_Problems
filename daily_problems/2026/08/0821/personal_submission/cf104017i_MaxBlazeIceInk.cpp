#include<bits/stdc++.h>
#include<cassert>
using namespace std;

#define MAXN 200005
#define INF (int)1e9

int n,a,b,p[MAXN],dp[MAXN],minn[MAXN << 2];

void build( int t , int l , int r ){
	if( l == r ){ minn[t] = dp[l]; return; }
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	minn[t] = min( minn[t << 1] , minn[t << 1 | 1] );
}

void modify( int t , int l , int r , int x , int k ){
	if( l == r ){ minn[t] = k; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x , k );
	else modify( t << 1 | 1 , mid + 1 , r , x , k );
	minn[t] = min( minn[t << 1] , minn[t << 1 | 1] );
}

int query( int t , int l , int r , int L , int R ){
	if( L <= l && r <= R ) return minn[t];
	int mid = ( l + r ) >> 1;
	if( R <= mid ) return query( t << 1 , l , mid , L , R );
	if( L > mid ) return query( t << 1 | 1 , mid + 1 , r , L , R );
	return min( query( t << 1 , l , mid , L , R ) , query( t << 1 | 1 , mid + 1 , r , L , R ) );
}

vector<int> T[MAXN];
inline void Brush(){
	for( int i = 1 ; i <= n ; i ++ ) if( i + p[i] + 1 <= n ) T[i + p[i] + 1].emplace_back( i );
	build( 1 , 1 , n );
	for( int r = 2 ; r <= n ; r ++ ){
		for( int ele : T[r] ) modify( 1 , 1 , n , ele , INF );
		int upd = query( 1 , 1 , n , max( r - p[r] , 1 ) , r - 1 ) + 1;
		if( upd < dp[r] ) dp[r] = upd,modify( 1 , 1 , n , r , dp[r] );
	}
	for( int i = 1 ; i <= n ; i ++ ) T[i].clear();
	for( int i = 1 ; i <= 4 * n ; i ++ ) minn[i] = 0;
}

inline void solve(){
	scanf("%d%d%d",&n,&a,&b);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&p[i]);
	for( int i = 1 ; i <= n ; i ++ ) dp[i] = INF; dp[a] = 0;
	for( int i = 0 ; i < 18 ; i ++ ){
		Brush();
		reverse( dp + 1 , dp + n + 1 );
		reverse( p + 1 , p + n + 1 );
	}
	printf("%d\n",dp[b]);
	for( int i = 1 ; i <= n ; i ++ ) T[i].clear();
	for( int i = 1 ; i <= 4 * n ; i ++ ) minn[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}