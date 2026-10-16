#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAXN 20005
#define int long long

const int V = 10000;
int n,a[MAXN],f[MAXN],tmp[MAXN];

inline void chkadd( int &x , int k ){ x += k; if( x >= mod ) x -= mod; }

signed main(){
	scanf("%lld",&n);
	// f[0 + V] = 1;
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		memcpy( tmp , f , sizeof( tmp ) );
		memset( f , 0 , sizeof( f ) );
		for( int j = -V ; j <= V ; j ++ ){
			if( j - a[i] >= -V ) chkadd( f[j - a[i] + V] , tmp[j + V] );
			if( j + a[i] <= V ) chkadd( f[j + a[i] + V] , tmp[j + V] );
		}
		chkadd( f[a[i] + V] , 1ll );
		chkadd( f[-a[i] + V] , 1ll );
		chkadd( ans , f[0 + V] );
	}
	printf("%lld\n",ans);
	return 0;
}