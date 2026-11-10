#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005

int n,a[MAXN],tmp[MAXN];

inline bool Test( int l1 , int r1 , int l2 , int r2 ){
	// cerr << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
	memcpy( tmp , a , sizeof( tmp ) );
	sort( tmp + l1 , tmp + r1 + 1 );
	sort( tmp + l2 , tmp + r2 + 1 );
	int c = 0;
	for( int i = 1 ; i <= 3 * n ; i ++ ) c += tmp[i] == i;
	if( c == 3 * n ){ printf("2\n%d %d\n%d %d\n",l1,r1,l2,r2); return 1; }
	return 0;
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= 3 * n ; i ++ ) scanf("%d",&a[i]);
	int c = 0;
	for( int i = 1 ; i <= 3 * n ; i ++ ) c += a[i] == i;
	if( c == 3 * n ){ puts("0"); return 0; }
	int l = 0,r = 3 * n;
	for( int i = 1 ; i <= 3 * n ; i ++ )
		if( a[i] != i ){ l = i; break; }
	for( int i = 1 ; i <= 3 * n ; i ++ )
		if( a[i] != i ) r = i;
	if( r - l + 1 <= 2 * n ){ printf("%d\n%d %d",1,l,r); return 0; }
	//上界应该是 3n
	if( Test( l , min( 3 * n , l + 2 * n - 1 ) , max( r - 2 * n + 1 , 1 ) , r ) ) return 0;
	if( Test( max( r - 2 * n + 1 , 1 ) , r , l , min( 3 * n , l + 2 * n - 1 ) ) ) return 0;
	printf("3\n%d %d\n%d %d\n%d %d\n",1,2 * n,n + 1,3 * n,1,2 * n);
	return 0;
}