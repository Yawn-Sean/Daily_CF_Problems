#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 100005

int n,q,a[MAXN],deg[MAXN],dfn[MAXN],ed[MAXN],idx,idf[MAXN];
int Gcd[MAXN << 2];
vector<int> E[MAXN];

int _gcd( int x , int y ){ return y ? _gcd( y , x % y ) : x; }

void modify( int t , int l , int r , int x , int k ){
	if( l == r ){ Gcd[t] = k; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x , k );
	else modify( t << 1 | 1 , mid + 1 , r , x , k );
	Gcd[t] = _gcd( Gcd[t << 1] , Gcd[t << 1 | 1] );
}

void build( int t , int l , int r ){
	if( l == r ){ Gcd[t] = a[idf[l]]; return; }
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	Gcd[t] = _gcd( Gcd[t << 1] , Gcd[t << 1 | 1] );
}

int query( int t , int l , int r , int Ql , int Qr ){
	if( Ql <= l && r <= Qr ) return Gcd[t];
	int mid = ( l + r ) >> 1;
	if( Qr <= mid ) return query( t << 1 , l , mid , Ql , Qr );
	if( Ql > mid ) return query( t << 1 | 1 , mid + 1 , r , Ql , Qr );
	return _gcd( query( t << 1 , l , mid , Ql , Qr ) , query( t << 1 | 1 , mid + 1 , r , Ql , Qr ) );
}

inline int Q( int x ){
	x = dfn[x];
	if( x == 1 ) return query( 1 , 1 , n , 2 , n );
	if( x == n ) return query( 1 , 1 , n , 1 , n - 1 );
	return _gcd( query( 1 , 1 , n , 1 , x - 1 ) , query( 1 , 1 , n , x + 1 , n ) );
}

void init( int x , int fa ){
	dfn[x] = ++idx,idf[idx] = x;
	for( int v : E[x] ){
		if( v == fa ) continue;
		init( v , x );
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	init( 1 , 0 );
	build( 1 , 1 , n );
	vector<int> A;
	for( int i = 1 ; i <= n ; i ++ ) if( (int)A.size() < 16 && E[i].size() == 1 ) A.emplace_back( i );
	scanf("%lld",&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int id,x; scanf("%lld%lld",&id,&x);
		modify( 1 , 1 , n , dfn[id] , x );
		a[id] = x;
		bool f = 0;
		for( int ele : A ){
			if( a[ele] == 1 || Q( ele ) == 1 ){
				f = 1; break;
			}
		}
		if( f ) puts("Yes");
		else puts("No");
	}
	return 0;
}