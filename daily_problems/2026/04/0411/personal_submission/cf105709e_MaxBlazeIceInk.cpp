#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,k,q,vis[MAXN],f[MAXN],siz[MAXN],lst[20];
vector<int> A[MAXN];
char s[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

signed main(){
	scanf("%d%d%d",&n,&k,&q);
	for( int i = 1 ; i <= n ; i ++ ){
		A[i].resize( k + 1 );
		scanf("%s",s + 1);
		for( int j = 1 ; j <= k ; j ++ ) A[i][j] = s[j] - 'a';
	}
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i,siz[i] = 1;
	int ans = 1;
	//随便 unite 一下
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%d",&op);
		if( op == 1 ){
			int x; scanf("%d",&x);
			if( vis[x] ) continue;
			//傻逼了
			vis[x] = 1;
			memset( lst , 0 , sizeof( lst ) );
			for( int j = 1 ; j <= n ; j ++ ){
				if( lst[A[j][x]] ){
					int u = j,v = lst[A[j][x]];
					if( find( u ) != find( v ) ){
						siz[find( u )] += siz[find( v )];
						f[find( v )] = find( u );
						ans = max( ans , siz[find( u )] );
					}
				}
				lst[A[j][x]] = j;
			}
		}
		else if( op == 2 ){
			int x; scanf("%d",&x);
			printf("%d\n",siz[find( x )]);
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}