#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define int long long

int n,r;
pair<int,int> p[MAXN];

signed main(){
	scanf("%lld%lld",&n,&r);
	int maxx = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&p[i].first,&p[i].second),maxx = max( maxx , p[i].second );
	sort( p + 1 , p + n + 1 );
	int g = 0;
	for( int i = 1 ; i < n ; i ++ ){
		int dt1 = ( p[i + 1].first - p[i].first ) * r;
		int dt2 = ( p[i + 1].second - p[i].second );
		g = gcd( g , abs( dt1 - dt2 ) );
	}
	if( g == 0 ){ printf("%lld\n",maxx + 1); return 0; }
	if( g <= maxx ){ puts("-1"); return 0; }
	int ans = g;
	for( int i = 1 ; i * i <= g ; i ++ ){
		if( g % i == 0 ){
			if( i > maxx ) ans = min( ans , i );
			if( g / i > maxx ) ans = min( ans , g / i );
		}
	}
	printf("%lld\n",ans);
	return 0;
}