#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 18

int n,f[1 << MAXN],vis[1 << MAXN],pre[MAXN],p[MAXN],deg[MAXN],topo[MAXN],ans[MAXN];
vector<int> E[MAXN];

inline int check_type(){
	char s[3]; scanf("%s",s + 1);
	if( s[1] == '?' ) return 1;
	else return 0;
}

inline pair<int,int> In(){
	int u,v;
	scanf("%lld%lld",&u,&v);
	return make_pair( u , v );
}

signed main(){
	scanf("%lld",&n);
	int tot = 1; for( int i = 1 ; i <= n ; i ++ ) tot *= i;
	while( check_type() ){
		pair<int,int> p = In();
		int u = p.first,v = p.second;
		E[u - 1].emplace_back( v - 1 );
		pre[v - 1] |= ( 1 << ( u - 1 ) );
		for( int S = 0 ; S < 1 << n ; S ++ ) f[S] = vis[S] = 0;
		f[0] = vis[0] = 1;
		for( int S = 0 ; S < 1 << n ; S ++ ){
			if( !vis[S] ) continue;
			for( int i = 0 ; i < n ; i ++ ){
				if( S >> i & 1 ) continue;
				if( ( pre[i] & S ) == pre[i] )
					f[S ^ ( 1 << i )] += f[S],vis[S ^ ( 1 << i )] = 1;
			}
		}
		if( 2 * f[( 1 << n ) - 1] < tot ){
			E[u - 1].pop_back();
			pre[v - 1] ^= ( 1 << ( u - 1 ) );
			E[v - 1].emplace_back( u - 1 );
			pre[u - 1] |= ( 1 << ( v - 1 ) );
			tot = tot - f[( 1 << n ) - 1];
			printf(">"); puts(""); fflush( stdout );
		}
		else{
			tot = f[( 1 << n ) - 1];
			printf("<"); puts("");
			fflush( stdout );
		}
	}
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&p[i]),topo[p[i] - 1] = i;
	for( int i = 0 ; i <= n ; i ++ )
		for( int v : E[i] ) deg[v] ++;
	priority_queue< pair<int,int> > Q;
	for( int i = 0 ; i < n ; i ++ ) if( !deg[i] ) Q.push( make_pair( topo[i] , i ) );
	int ord = 0;
	while( !Q.empty() ){
		int u = Q.top().second; Q.pop();
		ans[++ord] = u;
		for( int v : E[u] ) if( !--deg[v] ) Q.push( make_pair( topo[v] , v ) );
	}
	printf("!");
	for( int i = 1 ; i <= n ; i ++ ) printf(" %lld",ans[i] + 1);
	puts(""); fflush( stdout );
	return 0;
}