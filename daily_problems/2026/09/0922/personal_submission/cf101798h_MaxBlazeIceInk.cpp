#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,U[MAXN],V[MAXN],deg[MAXN],S[MAXN],vis[MAXN];
map<int,int> M[MAXN];
vector<int> E[MAXN];

vector<int> A,B;

inline bool check( int X1 , int X2 , int Y1 , int Y2 ){
	if( !M[X1].count( Y1 ) || !M[X2].count( Y2 ) ) return 0;
	A.clear(),B.clear();
	A.emplace_back( X1 ),A.emplace_back( X2 );
	B.emplace_back( Y1 ),B.emplace_back( Y2 );
	for( int i = 3 ; i <= n / 2 ; i ++ ){
		int u1 = A.back(),v1 = A[A.size() - 2];
		int u2 = B.back(),v2 = B[B.size() - 2];
		int nu1 = S[u1] - v1 - u2;
		if( !M[u1].count( nu1 ) ) return 0;
		int nu2 = S[u2] - v2 - u1;
		if( !M[u2].count( nu2 ) ) return 0;
		if( !M[nu1].count( nu2 ) ) return 0;
		A.emplace_back( nu1 ),B.emplace_back( nu2 );
	}
	if( !M[A.back()].count( X1 ) || !M[B.back()].count( Y1 ) ) return 0;
	for( int i = 1 ; i <= n ; i ++ ) vis[i] = 0;
	for( int ele : A ) vis[ele] = 1;
	for( int ele : B ) vis[ele] = 1;
	for( int i = 1 ; i <= n ; i ++ ) if( !vis[i] ) return 0;
	return 1;
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n / 2 * 3 ; i ++ ){
		scanf("%d%d",&U[i],&V[i]);
		deg[U[i]] ++,deg[V[i]] ++;
		S[U[i]] += V[i],S[V[i]] += U[i];
		E[U[i]].emplace_back( V[i] );
		E[V[i]].emplace_back( U[i] );
	}
	for( int i = 1 ; i <= n ; i ++ ) if( deg[i] != 3 ){ puts("NO"); return 0; }
	for( int i = 1 ; i <= n / 2 * 3 ; i ++ ) M[U[i]][V[i]] = M[V[i]][U[i]] = 1;
	for( int u : E[1] ){
		for( int v : E[u] ){
			for( int w : E[v] ){
				set<int> S; S.insert( v ),S.insert( w ),S.insert( u ),S.insert( 1 );
				if( S.size() == 4 ){
					if( check( 1 , u , w , v ) ){
						puts("YES");
						for( int ele : A ) printf("%d ",ele); puts("");
						for( int ele : B ) printf("%d ",ele); puts("");
						return 0;
					}
				}
			}
		}
	}
	puts("NO");
	return 0;
}