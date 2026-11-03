#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n,m,q,a[MAXN],mus[MAXN],inc[MAXN],non[MAXN];

inline void solve(){
	scanf("%d%d",&n,&m);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	int c = 0;
	for( int i = 1 ; i <= n ; i ++ ) c += a[i] == a[1];
	scanf("%d",&q);
	if( c == n ){
		for( int i = 1 ; i <= q ; i ++ ){
			int x; scanf("%d",&x);
			puts("0");
		}
		return;
	}
	for( int i = 0 ; i < 30 ; i ++ ){
		int c = 0;
		for( int j = 1 ; j <= n ; j ++ ) c += a[j] >> i & 1;
		if( c == n ) continue;
		if( c ){
			inc[i] = 1;
			for( int j = 1 ; j <= n ; j ++ ){
				if( !( a[j] >> i & 1 ) ){
					mus[j] = 1;	
				}
			}
		}
		else non[i] = 1;
	}
	int res = 0;
	for( int i = 1 , now = 0 ; i <= n ; i ++ ){
		if( mus[i] ){
			if( !now ) now = m,res ++;
		}
		now = max( now - 1 , 0 );
	}
	for( int i = 1 ; i <= q ; i ++ ){
		int x; scanf("%d",&x);
		int ans = 0;
		bool f = 1;
		for( int j = 0 ; j < 30 ; j ++ ){
			if( inc[j] && !( x >> j & 1 ) ){
				f = 0;
				puts("-1");
				break;
			}
			if( non[j] && ( x >> j & 1 ) ){
				ans = ( n + m - 1 ) / m;
			}
			if( inc[j] ) ans = max( ans , res );
		}
		if( f )
		//输出 res 是人类啊
		printf("%d\n",ans);
	}
	for( int i = 1 ; i <= n ; i ++ ) mus[i] = 0;
	for( int j = 0 ; j < 30 ; j ++ ) inc[j] = non[j] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}