#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,m,x,f[MAXN],minn[MAXN][18],dep[MAXN],Fa[MAXN][18],ison[MAXN];
struct edge{ int u,v,w; }E[MAXN];
vector< pair<int,int> > E2[MAXN];

inline bool cmp( edge A , edge B ){ return A.w < B.w; }

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

void init( int x , int fa ){
	dep[x] = dep[fa] + 1,Fa[x][0] = fa;
	for( pair<int,int> p : E2[x] ){
		int v = p.first,w = p.second;
		if( v == fa ) continue;
		init( v , x ),minn[v][0] = w;
	}
}

inline int Lca( int u , int v ){
	if( dep[u] != dep[v] ){
		if( dep[u] < dep[v] ) swap( u , v );
		for( int i = 17 ; i >= 0 ; i -- )
			if( dep[Fa[u][i]] >= dep[v] ) u = Fa[u][i];
	}
	if( u == v ) return u;
	for( int i = 17 ; i >= 0 ; i -- ){
	 	if( Fa[u][i] == Fa[v][i] ) continue;
	 	u = Fa[u][i],v = Fa[v][i];
	}
	return Fa[u][0];
}

inline int query( int u , int v ){
	int X = Lca( u , v );
	int res = 0;
	for( int i = 17 ; i >= 0 ; i -- )
		if( dep[Fa[u][i]] >= dep[X] )
			res = max( res , minn[u][i] ),u = Fa[u][i];
	for( int i = 17 ; i >= 0 ; i -- )
		if( dep[Fa[v][i]] >= dep[X] )
			res = max( res , minn[v][i] ),v = Fa[v][i];
	return res;
}

inline void solve(){
	scanf("%lld%lld%lld",&n,&m,&x);
	for( int i = 1 ; i <= m ; i ++ )
		scanf("%lld%lld%lld",&E[i].u,&E[i].v,&E[i].w);
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i;
	sort( E + 1 , E + m + 1 , cmp );
	int S = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		int u = E[i].u,v = E[i].v,w = E[i].w;
		if( find( u ) == find( v ) ) continue;
		u = find( u ),v = find( v );
		f[u] = v,S += w,ison[i] = 1;
		E2[u].emplace_back( make_pair( v , w ) );
		E2[v].emplace_back( make_pair( u , w ) );
	}
	init( 1 , 0 );
	for( int j = 1 ; j < 18 ; j ++ )
		for( int i = 1 ; i <= n ; i ++ ){
			Fa[i][j] = Fa[Fa[i][j - 1]][j - 1];
			minn[i][j] = max( minn[i][j - 1] , minn[Fa[i][j - 1]][j - 1] );
		}
	int res = (int)2e18;
	if( m == n - 1 ){
		for( int i = 1 ; i <= m ; i ++ )
			res = min( res , S - E[i].w + ( E[i].w ^ x ) );
		printf("%lld\n",res);
	}
	else{
		for( int i = 1 ; i <= m ; i ++ ){
			int u = E[i].u,v = E[i].v,w = E[i].w;
			if( ison[i] ){
				if( ( w ^ x ) <= w ){
					res = min( res , S - w + ( w ^ x ) );
				}
				else res = min( res , S );
			}
			else{
				int p = query( u , v );
				res = min( res , S + ( w ^ x ) - p );
			}
		}
		printf("%lld\n",res);
	}
	for( int i = 1 ; i <= n ; i ++ ){
		E2[i].clear();
		for( int j = 0 ; j < 18 ; j ++ ) Fa[i][j] = minn[i][j] = 0;
		f[i] = dep[i] = 0;
	}
	for( int i = 1 ; i <= m ; i ++ ) E[i] = edge{ 0 , 0 , 0 },ison[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}