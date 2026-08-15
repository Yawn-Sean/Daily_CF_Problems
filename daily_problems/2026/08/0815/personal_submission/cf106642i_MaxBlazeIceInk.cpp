#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,q,dep[MAXN],fa[18][MAXN],dfn[MAXN],idx,ed[MAXN];
vector<int> E[MAXN];

int add[MAXN << 2],minn[MAXN << 2],minc[MAXN << 2];

inline void push_up( int t ){
	if( minn[t << 1] < minn[t << 1 | 1] ) minn[t] = minn[t << 1],minc[t] = minc[t << 1];
	else if( minn[t << 1] > minn[t << 1 | 1] ) minn[t] = minn[t << 1 | 1],minc[t] = minc[t << 1 | 1];
	else minn[t] = minn[t << 1],minc[t] = minc[t << 1] + minc[t << 1 | 1];
}

inline void update( int t , int k ){ minn[t] += k,add[t] += k; }
inline void push_down( int t ){
	if( add[t] ) update( t << 1 , add[t] ),update( t << 1 | 1 , add[t] );
	add[t] = 0;
}

void modify( int t , int l , int r , int L , int R , int k ){
	if( L <= l && r <= R ){ update( t , k ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( L <= mid ) modify( t << 1 , l , mid , L , R , k );
	if( R > mid ) modify( t << 1 | 1 , mid + 1 , r , L , R , k );
	push_up( t );
}

void dfs( int x , int Fa ){
	dep[x] = dep[Fa] + 1,fa[0][x] = Fa,dfn[x] = ++idx;
	for( int v : E[x] ){
		if( v == Fa ) continue;
		dfs( v , x );
	}
	ed[x] = idx;
}

void build( int t , int l , int r ){
	if( l == r ){ minn[t] = 0,minc[t] = 1; return; }
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	push_up( t );
}

inline int Lca( int u , int v ){
	if( dep[u] != dep[v] ){
		if( dep[u] < dep[v] ) swap( u , v );
		for( int i = 17 ; i >= 0 ; i -- )
			if( dep[fa[i][u]] >= dep[v] ) u = fa[i][u];
	}
	if( u == v ) return u;
	for( int i = 17 ; i >= 0 ; i -- )
		if( fa[i][u] != fa[i][v] )
			u = fa[i][u],v = fa[i][v];
	return fa[0][u];
}

inline int find_near( int x , int v ){
	for( int i = 17 ; i >= 0 ; i -- )
		if( dep[fa[i][v]] > dep[x] ) v = fa[i][v];
	return v;
}

inline int find_k( int v , int k ){
	for( int i = 17 ; i >= 0 ; i -- ){
		if( k >= 1 << i ) v = fa[i][v],k -= 1 << i;
	}
	return v;
}

signed main(){
	scanf("%lld%lld",&n,&q);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
	}
	dfs( 1 , 0 );
	build( 1 , 1 , n );
	for( int j = 1 ; j < 18 ; j ++ )
		for( int i = 1 ; i <= n ; i ++ ) fa[j][i] = fa[j - 1][fa[j - 1][i]];
	for( int i = 1 ; i <= q ; i ++ ){
		int u,v,x,y,z; scanf("%lld%lld%lld%lld%lld",&u,&v,&x,&y,&z);
		if( u == v ) modify( 1 , 1 , n , 1 , n , z );
		else{
			int X = Lca( u , v );
			// cerr << X << "\n";
			if( dep[u] == dep[v] ){
				int U = find_near( X , u ),V = find_near( X , v );
				// cerr << U << " " << V << "\n";
				modify( 1 , 1 , n , 1 , n , z );
				modify( 1 , 1 , n , dfn[U] , ed[U] , x - z );
				modify( 1 , 1 , n , dfn[V] , ed[V] , y - z );
			}
			else{
				if( dep[u] < dep[v] ) swap( u , v ),swap( x , y );
				int L = dep[u] + dep[v] - 2 * dep[X];
				if( L % 2 ){
					int U = find_k( u , L / 2 );
					modify( 1 , 1 , n , 1 , n , y );		
					modify( 1 , 1 , n , dfn[U] , ed[U] , x - y );
				}
				else{
					int U = find_k( u , L / 2 - 1 );
					modify( 1 , 1 , n , 1 , n , y );
					modify( 1 , 1 , n , dfn[fa[0][U]] , ed[fa[0][U]] , z - y );
					modify( 1 , 1 , n , dfn[U] , ed[U] , x - z );
				}
			}
		}
		printf("%lld %lld\n",minn[1],minc[1]);
	}
	return 0;
}