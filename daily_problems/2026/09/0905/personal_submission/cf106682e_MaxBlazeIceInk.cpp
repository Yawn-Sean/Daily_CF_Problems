#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,a[MAXN],c[MAXN],vis[MAXN];
map<int,int> M;
vector<int> E[MAXN];

void judge( int x , int fa ){
	vis[x] = 1;
	for( int v : E[x] ){
		if( v == fa ) continue;
		judge( v , x );
		int t = min( c[x] , c[v] );
		c[x] -= t,c[v] -= t;
	}
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d",&a[i],&c[i]);
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 0 ; j <= 30 ; j ++ ){
			if( M.count( ( 1ll << j ) - 1 - a[i] ) ){
				int id = M[( 1ll << j ) - 1 - a[i]];
				E[i].emplace_back( id );
				E[id].emplace_back( i );
			}
		}
		M[a[i]] = i;
	}
	for( int i = 1 ; i <= n ; i ++ ) if( !vis[i] ) judge( i , 0 );
	int t = 0;
	for( int i = 1 ; i <= n ; i ++ ) t += c[i] > 0;
	if( t ) puts("Ana");
	else puts("Beto");
	return 0;
}