#include<bits/stdc++.h>
using namespace std;

#define int long long
int a,b,c,d;

signed main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if( a == b ){
		if( c != d ) puts("0");
		else{
			int v = 2 * c / ( 2 * a + 1 );
			printf("%lld\n",c - a * v);
		}
	}
	else{
		if( ( d - c ) % ( b - a ) ) puts("0");
		else{
			int v = ( d - c ) / ( b - a );
			if( v < 0 ) puts("0");
			else if( c - a * v < ( v + 1 ) / 2 ) puts("0");
			else printf("%lld\n",c - a * v);
		}
	}
	return 0;
}