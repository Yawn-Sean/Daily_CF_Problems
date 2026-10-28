#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005
#define mod 998244353
#define INF (int)1e18

int n,X[MAXN],Y[MAXN];

inline bool exist( int x , int y ){
	for( int i = 1 ; i <= n ; i ++ )
		if( X[i] == x && Y[i] == y ) return 1;
	return 0;
}

inline void solve(){
	scanf("%lld",&n);
	int maxX = -INF,maxY = -INF,minX = INF,minY = INF;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&X[i],&Y[i]),maxX = max( maxX , X[i] ),minX = min( minX , X[i] ),maxY = max( maxY , Y[i] ),minY = min( minY , Y[i] );
	if( exist( maxX , maxY ) && exist( maxX , minY ) && exist( minX , maxY ) && exist( minX , minY ) ){
		puts("YES");
	}
	else puts("NO");
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}