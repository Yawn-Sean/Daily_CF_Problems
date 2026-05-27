#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005
int n,k,a[MAXN],b[MAXN],p[MAXN];

inline bool cmp( int u , int v ){ return b[u] < b[v]; }

inline void solve(){
	scanf("%lld%lld",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld%lld",&a[i],&b[i]),p[i] = i;
	sort( p + 1 , p + n + 1 , cmp );
	priority_queue< int , vector<int> , greater<int> > Q;
	int res = 0,ans = -(int)1e18;
	for( int i = 1 ; i <= n ; i ++ ){
		int I = p[i]; res -= b[I];
		if( (int)Q.size() < k ) res += a[I],Q.push( a[I] );
		else{
			res -= Q.top(),Q.pop(),res += a[I],Q.push( a[I] );
		}
		if( (int)Q.size() == k ) ans = max( ans , res );
		res += b[I];
	}
	printf("%lld\n",ans);
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}