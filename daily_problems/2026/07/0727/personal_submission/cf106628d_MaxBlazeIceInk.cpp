#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,k,a[MAXN];

inline void solve(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	int l = 0,r = 30,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		map<int,int> M;
		int U = ( 1 << mid ) - 1,flg = 0;
		for( int i = 1 ; i <= n ; i ++ ){
			if( ++M[a[i] & U] >= k ){
				flg = 1;
				break;
			}
		}
		if( flg ) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n",1ll * ( k - 1 ) * ( 1 << ans ));
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}