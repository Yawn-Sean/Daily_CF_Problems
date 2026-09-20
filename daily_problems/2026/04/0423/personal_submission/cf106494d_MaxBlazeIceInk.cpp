#include<bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define int long long

int n,a[MAXN],s[MAXN];

inline int judge( int r , int x ){
	//真的糖丸了这里
	if( r + x == 0 ) return (int)-1e18;  
	if( ( r + x ) % 2 ){
		return a[( r + x ) / 2 + 1];
	}
	else{
		return ( a[( r + x ) / 2] + a[( r + x ) / 2 + 1] ) / 2;
	}
}

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]),a[i] *= 2;
	sort( a + 1 , a + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) s[i] = s[i - 1] + a[i];
	int r = 0;
	for( int i = 1 ; i <= n ; i ++ ) if( a[i] < 0 ) r = i;
	int Ans = judge( r , 0 ) + s[n] - s[r];
	for( int i = 1 ; r + i <= n ; i ++ ){
		Ans = max( Ans , judge( r , i ) + s[n] - s[r + i] );
	}
	printf("%lld\n",Ans);
	return 0;
}