#include<bits/stdc++.h>
using namespace std;

#define MAXN 105
int n,x[MAXN],y[MAXN],z[MAXN],r[MAXN],p[MAXN];
vector<int> E;

inline bool cmp( int u , int v ){ return r[u] < r[v]; }

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ )
		scanf("%d%d%d%d",&x[i],&y[i],&z[i],&r[i]),p[i] = i;
	sort( p + 1 , p + n + 1 , cmp );
	for( int i = n ; i >= 1 ; i -- ){
		int has = 1,I = p[i];
		for( int ele : E ){
			int T = ( x[ele] - x[I] ) * ( x[ele] - x[I] ) + ( y[ele] - y[I] ) * ( y[ele] - y[I] ) + ( z[ele] - z[I] ) * ( z[ele] - z[I] );
			int P = ( r[I] + r[ele] ) * ( r[I] + r[ele] );
			if( T < P ) has = 0;
		}
		if( has ){
			E.emplace_back( I );
		}
	}
	printf("%d\n",(int)E.size());
	for( int ele : E ) printf("%d ",ele);
	puts("");
	return 0;
}