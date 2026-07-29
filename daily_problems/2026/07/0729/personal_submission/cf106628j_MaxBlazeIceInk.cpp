#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,zs[MAXN],zt[MAXN],L[MAXN],R[MAXN];
char s[MAXN],t[MAXN];

inline void solve(){
	scanf("%s",s + 1); n = strlen( s + 1 );
	memcpy( t , s , sizeof( s ) );
	reverse( t + 1 , t + n + 1 );
	for( int x = 2 , k = 1 ; x <= n ; x ++ ){
		if( x + zs[x - k + 1] < k + zs[k] ) zs[x] = zs[x - k + 1];
		else{
			zs[x] = k + zs[k] - x;
			if( zs[x] < 0 ) zs[x] = 0;
			while( x + zs[x] <= n && s[x + zs[x]] == s[zs[x] + 1] ) zs[x] ++;
			k = x;
		}
	}
	for( int x = 2 , k = 1 ; x <= n ; x ++ ){
		if( x + zt[x - k + 1] < k + zt[k] ) zt[x] = zt[x - k + 1];
		else{
			zt[x] = k + zt[k] - x;
			if( zt[x] < 0 ) zt[x] = 0;
			while( x + zt[x] <= n && t[x + zt[x]] == t[zt[x] + 1] ) zt[x] ++;
			k = x;
		}
	}
	// for( int i = 1 ; i <= n ; i ++ ) cerr << zs[i] << "\n";
	//选择 [i,n] 作为 C
	int ans = 0;
	for( int i = 3 ; i <= n ; i ++ ){
		if( !zs[i] || !zt[n - i + 2] ) continue;
		int ra = min( zs[i] , n - i + 1 );
		int rb = min( zt[n - i + 2] , n - i + 1 );
		//1 <= x <= ra,1 <= i - 1 - x <= rb
		//x <= i - 2,x >= i - 1 - rb
		int L = max( 1ll , i - 1 - rb ),R = min( ra , i - 2 );
		// cerr << i << " " << L << " " << R << "\n";
		if( L <= R ) ans += R - L + 1;
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) zs[i] = zt[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}