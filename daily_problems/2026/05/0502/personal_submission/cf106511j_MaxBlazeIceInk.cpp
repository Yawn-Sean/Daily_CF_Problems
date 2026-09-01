#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN],b[MAXN],f[MAXN],siz[MAXN];

int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }

int Gcd( int x , int y ){ return y ? Gcd( y , x % y ) : x; }

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]);
	set<int> A,B;
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i,siz[i] = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		int u = i,v = a[i];
		u = find( u ),v = find( v ); if( u == v ) continue;
		siz[v] += siz[u],f[u] = v;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( find( i ) == i ) A.insert( siz[i] );
	for( int i = 1 ; i <= n ; i ++ ) f[i] = i,siz[i] = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		int u = i,v = b[i];
		u = find( u ),v = find( v ); if( u == v ) continue;
		siz[v] += siz[u],f[u] = v;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( find( i ) == i ) B.insert( siz[i] );
	int Ans = 0;
	for( int ele : A ){
		int res = (int)1e18;
		for( int ele2 : B ){
			int r = ele * ele2 / Gcd( ele , ele2 );
			res = min( res , r );
		}
		Ans = max( Ans , res );
	}
	printf("%lld\n",Ans);
	return 0;
}