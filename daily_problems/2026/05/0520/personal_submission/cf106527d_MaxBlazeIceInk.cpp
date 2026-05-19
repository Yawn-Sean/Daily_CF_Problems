#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

mt19937_64 rnd(20070414);

int n,m,deg[MAXN],vis[MAXN][67],ans[MAXN];
char s[10];
struct node{ int v,w,id; };

vector<node> E[MAXN];

inline void solve(){
	scanf("%d%d%s",&n,&m,s + 1); int len = strlen( s + 1 );
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( node{ v , 0 , i } );
		deg[v] ++;
	}
	queue<int> Q;
	for( int i = 1 ; i <= n ; i ++ ) if( !deg[i] ) Q.push( i );
	while( !Q.empty() ){
		int u = Q.front(); Q.pop();
		for( node p : E[u] ){
			int v = p.v;
			if( !--deg[v] ) Q.push( v );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) if( deg[i] ){ puts("NO"); return; }
	int c = 0;
	while( 1 ){
		for( int i = 1 ; i <= n ; i ++ )
			for( node &p : E[i] ) p.w = s[1] - '0',ans[p.id] = p.w,deg[p.v] ++;
		memset( vis , 0 , sizeof( vis ) );
		for( int i = 1 ; i <= n ; i ++ ) if( !deg[i] ) Q.push( i );
		while( !Q.empty() ){
			int u = Q.front(); Q.pop();
			for( node p : E[u] ){
				int v = p.v,w = p.w;
				for( int i = 0 ; i < 67 ; i ++ ) vis[v][( i + w ) % 67] |= vis[u][i];
				vis[v][w] = 1;
				if( !--deg[v] ) Q.push( v );
			}
		}
		bool flag = 1;
		for( int i = 1 ; i <= n ; i ++ ) if( vis[i][0] ){ flag = 0; break; }
		if( flag ) break;
		c ++;
		if( c >= 2 ){ puts("NO"); return; }
	}
	puts("YES");
	for( int i = 1 ; i <= m ; i ++ ) printf("%d\n",ans[i]);
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}