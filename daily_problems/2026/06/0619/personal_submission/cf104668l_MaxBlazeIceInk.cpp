#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
int n,a,b,x[MAXN];

signed main(){
	scanf("%d%d%d",&n,&a,&b);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&x[i]);
	if( a == b ){
		int ans = 0;
		for( int i = 1 ; i <= n ; i ++ ) ans ^= x[i] % ( a + 1 );
		if( ans ) puts("Petyr");
		else puts("Varys");
	}
	else if( a > b ){
		int maxx = 0;
		for( int i = 1 ; i <= n ; i ++ ) maxx = max( maxx , x[i] );
		if( maxx <= b ){
			int ans = 0;
			for( int i = 1 ; i <= n ; i ++ ) ans ^= x[i] % ( b + 1 );
			if( ans ) puts("Petyr");
			else puts("Varys");
		}
		else puts("Petyr");
	}
	else{
		int res = 0;
		for( int i = 1 ; i <= n ; i ++ ) res += x[i] > a;
		if( res >= 2 ) puts("Varys");
		else if( !res ){
			int ans = 0;
			for( int i = 1 ; i <= n ; i ++ ) ans ^= x[i] % ( a + 1 );
			if( ans ) puts("Petyr");
			else puts("Varys");
		}
		else{
			int ans = 0,maxx = 0;
			for( int i = 1 ; i <= n ; i ++ ){
				if( x[i] <= a ) ans ^= x[i] % ( a + 1 );
				maxx = max( maxx , x[i] );
			}
			int ned = maxx - ans;
			//ans > a：目标也不能 >a
			if( ans > a || ned > a ) puts("Varys");
			else puts("Petyr"); 
		}
	}
	return 0;
}