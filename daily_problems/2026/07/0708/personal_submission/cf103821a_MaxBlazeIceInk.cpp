#include<bits/stdc++.h>
using namespace std;

#define MAXN 800005

int n,q,id[MAXN][2],cnt,dp[MAXN],deg[MAXN],vis[MAXN];
vector< array<int,3> > Q[MAXN];

vector<int> E[MAXN];
int val[MAXN << 2],tag[MAXN << 2];

inline void update( int t , int k ){ val[t] = tag[t] = k; }

inline void push_down( int t ){
	if( tag[t] ) update( t << 1 , tag[t] ),update( t << 1 | 1 , tag[t] );
	tag[t] = 0;
}

void modify( int t , int l , int r , int Ql , int Qr , int k ){
	if( Ql <= l && r <= Qr ){ update( t , k ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( Ql <= mid ) modify( t << 1 , l , mid , Ql , Qr , k );
	if( Qr > mid ) modify( t << 1 | 1 , mid + 1 , r , Ql , Qr , k );
}

int query( int t , int l , int r , int x ){
	if( l == r ) return val[t];
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( x <= mid ) return query( t << 1 , l , mid , x );
	else return query( t << 1 | 1 , mid + 1 , r , x );
}

inline void solve(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r,x; scanf("%d%d%d",&l,&r,&x);
		Q[x].emplace_back( array<int,3>{ l , r , i } );
	}
	cnt = 2 * n;
	for( int i = 1 ; i <= q ; i ++ ) id[i][0] = ++cnt,id[i][1] = ++cnt;
	for( int y = n - 1 ; y >= 1 ; y -- ){
		for( array<int,3> t : Q[y] ){
			int l = get<0>(t),r = get<1>(t),Id = get<2>(t);
			int L = query( 1 , 1 , n , l ),R = query( 1 , 1 , n , r );
			if( !L ) E[id[Id][0]].emplace_back( l );
			else E[id[Id][0]].emplace_back( id[L][0] ),E[id[Id][0]].emplace_back( id[L][1] );
			if( !R ) E[id[Id][1]].emplace_back( r );
			else E[id[Id][1]].emplace_back( id[R][0] ),E[id[Id][1]].emplace_back( id[R][1] );
			modify( 1 , 1 , n , l , r , Id );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		int p = query( 1 , 1 , n , i );
		if( !p ) E[i + n].emplace_back( i ); //这能写错？？？？
		else E[i + n].emplace_back( id[p][0] ),E[i + n].emplace_back( id[p][1] );
	}
	for( int i = 1 ; i <= cnt ; i ++ )
		for( int ele : E[i] ) deg[ele] ++;//cerr << i << " " << ele << "\n";
	queue<int> Q2;
	for( int i = 1 ; i <= n ; i ++ ) dp[i + n] = 1,Q2.push( i + n ),vis[i + n] = 1;
	while( !Q2.empty() ){
		int u = Q2.front(); Q2.pop();
		// cerr << u << "\n";
		for( int v : E[u] ){
			if( vis[v] ) continue;
			dp[v] |= dp[u];
			Q2.push( v ),vis[v] = 1;
		}
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) ans += dp[i];
	printf("%d\n",ans);
	for( int i = 1 ; i <= max( cnt , q ) ; i ++ ) E[i].clear(),dp[i] = deg[i] = vis[i] = 0,Q[i].clear(),id[i][0] = id[i][1] = 0;
	for( int i = 1 ; i <= 4 * n ; i ++ ) val[i] = tag[i] = 0;
	cnt = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}