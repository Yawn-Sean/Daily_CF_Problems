#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,p[MAXN],q[MAXN];

//不难发现要取前缀上最长一段同构

inline bool check( int x ){
	vector<int> A,B;
	for( int i = 1 ; i <= n ; i ++ ) if( p[i] <= x ) A.emplace_back( p[i] );
	for( int i = 1 ; i <= m ; i ++ ) if( q[i] <= x ) B.emplace_back( q[i] );
	return A == B;
}

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&p[i]);
	for( int i = 1 ; i <= m ; i ++ ) scanf("%d",&q[i]);
	int l = 1,r = min( n , m ),ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) ) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n",n + m - 2 * ans);
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}