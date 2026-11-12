#include<bits/stdc++.h>
using namespace std;

#define MAXN 305

int n,p[MAXN],Fa[MAXN];
set<int> E[MAXN];

void dfs( int x , int fa ){
	Fa[x] = fa;
	for( int v : E[x] ){
		if( v == fa ) continue;
		dfs( v , x );
	}
}

inline void clear(){
	for( int i = 1 ; i <= n ; i ++ ) E[i].clear(),Fa[i] = 0;
}

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&p[i]);
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].insert( v ),E[v].insert( u );
	}
	dfs( p[1] , 0 );
	vector< array<int,3> > ans;
	for( int i = 1 ; i < n ; i ++ ){
		int a = p[i + 1],b = Fa[p[i + 1]],c = Fa[b];
		//一点点剥
		while( c ){
			ans.push_back( { a , b , c } );
			E[a].erase( b ),E[b].erase( a );
			E[a].insert( c ),E[c].insert( a );
			Fa[a] = c;
			b = c,c = Fa[c];
		}
		dfs( a , 0 );
		// for( int i = 1 ; i <= 4 ; i ++ )cerr << i << " " << Fa[i] << "\n";
	}
	printf("%d\n",(int)ans.size());
	for( auto [a,b,c] : ans ){
		printf("%d %d %d\n",a,b,c);
	}
	clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}