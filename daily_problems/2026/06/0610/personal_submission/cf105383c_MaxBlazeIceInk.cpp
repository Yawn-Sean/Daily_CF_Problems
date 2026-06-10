#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 500005

int n,a[MAXN],b[MAXN],tr[MAXN],v[MAXN],pos[MAXN],to[MAXN],ord[MAXN];
int ansb[MAXN];

inline void add( int x , int k ){ for( ; x <= n ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

pair<int,int> p[MAXN];

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&b[i]),ord[b[i]] = a[i],p[i] = make_pair( a[i] , b[i] );
	int A = 0,B = 0;
	for( int i = 1 ; i <= n ; i ++ )
		A += i - 1 - sum( a[i] ),add( a[i] , 1 );
	for( int i = 1 ; i <= n ; i ++ ) tr[i] = 0;
	for( int i = 1 ; i <= n ; i ++ )
		B += i - 1 - sum( b[i] ),add( b[i] , 1 );
	for( int i = 1 ; i <= n ; i ++ ) tr[i] = 0;
	if( A % 2 != B % 2 ){ puts("No"); return 0; }
	sort( p + 1 , p + n + 1 );
	B = 0;
	// for( int i = 1 ; i <= n ; i ++ ) cerr << p[i].first << " " << p[i].second << "\n";
	for( int i = n ; i >= 1 ; i -- )
		v[p[i].second] = sum( p[i].second ),add( p[i].second , 1 ),B += v[p[i].second],pos[p[i].second] = i;
	B /= 2;
	// cerr << B << "\n";
	for( int i = 1 ; i <= n ; i ++ ) tr[i] = 0;
	for( int V = n , r = n ; V >= 1 ; V -- ){
		int rea = pos[V] - sum( pos[V] );
		int Jud = r - rea;
		if( Jud <= B ) B -= Jud,to[pos[V]] = r,add( pos[V] , 1 );
		else{ if( B ) to[pos[V]] = rea + B,B = 0; }
		if( !B ) break;
		r --;
	}
	for( int i = 1 ; i <= n ; i ++ )
		if( to[i] ) ansb[to[i]] = p[i].second;
	int pnt = 1;
	for( int i = 1 ; i <= n ; i ++ ){
		while( ansb[pnt] ) pnt ++;
		if( !to[i] ) ansb[pnt] = p[i].second;
	}
	puts("Yes");
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ord[ansb[i]]);
	puts("");
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",ansb[i]);
	return 0;
}