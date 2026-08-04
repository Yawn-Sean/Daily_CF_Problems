#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,a[MAXN],w[MAXN],cnt[MAXN];

inline void solve(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld",&a[i]);
		if( a[i] <= n ) cnt[a[i]] ++;
	}
	multiset<int> S;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&w[i]);
	int ans = 0;
	for( int i = n ; i >= 1 ; i -- ){
		S.insert( w[i] );
		for( int j = 1 ; j <= cnt[i] ; j ++ ){
			if( !S.size() ) continue;
			ans += *S.rbegin(); S.erase( S.find( *S.rbegin() ) );
		}
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) cnt[i] = 0;
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}