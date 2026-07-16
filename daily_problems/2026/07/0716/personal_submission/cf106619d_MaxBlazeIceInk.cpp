#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int In(){
	int x; scanf("%lld",&x);
	return x;
}

inline int Ask( int m , int v ){
	printf("? %lld %lld\n",m,v); fflush( stdout );
	return In();
}

int sam[60];

inline void solve(){
	int sig = -1,A = 0,B = 0;
	for( int i = 59 ; i >= 0 ; i -- ){
		int p = Ask( 1ll << i , 1ll << i );
		if( p % 2 == 0 )
			sam[i] = 1;
		else{
			if( sig == -1 ) sig = i,B += 1ll << i;
			sam[i] = 0;
		}
	}
	for( int i = 59 ; i >= 0 ; i -- ){
		if( i == sig ) continue;
		int p = Ask( ( 1ll << i ) + ( 1ll << sig ) , ( 1ll << i ) + ( 1ll << sig ) );
		if( p % 2 == 0 ){
			A += ( 1ll ^ sam[i] ) << i;
		}
		else{
			B += 1ll << i;
			A += sam[i] << i;
		}
	}
	printf("! %lld %lld\n",A,B); fflush( stdout );
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}