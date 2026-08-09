#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1000005

int n,x,y,z,border[2][MAXN],suf[MAXN];
char s[MAXN];

inline void find( int t ){
	for( int i = 2 , j = 0 ; i <= n ; i ++ ){
		while( j && s[j + 1] != s[i] ) j = border[t][j];
		if( s[j + 1] == s[i] ) j ++; border[t][i] = j;
	}
}

signed main(){
	scanf("%lld%lld%lld%lld%s",&n,&x,&y,&z,s + 1);
	find( 0 ); reverse( s + 1 , s + n + 1 );
	find( 1 ); reverse( s + 1 , s + n + 1 );
	reverse( border[1] + 1 , border[1] + n + 1 );
	suf[n] = (int)-1e18;
	for( int i = n - 1 ; i >= 1 ; i -- )
		if( border[1][i] )
		suf[i] = max( suf[i + 1] , border[1][i] * y + ( i - 1 ) * z );
		else suf[i] = suf[i + 1];
	int ans = 0;
	for( int i = 2 ; i < n ; i ++ )
		if( border[0][i] )
		ans = max( ans , border[0][i] * x - i * z + suf[i + 1] );
	printf("%lld\n",ans);
	//pre[i] + suf[j] + ( j - i - 1 ) * z
	return 0;
}