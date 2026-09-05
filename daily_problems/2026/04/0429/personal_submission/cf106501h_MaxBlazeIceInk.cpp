#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")

using namespace std;

typedef long long ll;
#define MAXN 200005

int n,k,X,a[MAXN],b[MAXN],vs[MAXN],vcnt,C[MAXN];
ll ans = 0;

int cnt[MAXN << 2];
ll sum[MAXN << 2];

void build( int t , int l , int r ){
	if( l == r ){ cnt[t] = C[l],sum[t] = 1ll * C[l] * vs[l]; return; }
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	cnt[t] = cnt[t << 1] + cnt[t << 1 | 1];
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

void modify( int t , int l , int r , int x , int k ){
	if( l == r ){ cnt[t] += k,sum[t] += vs[l] * k; return; }
	int mid = ( l + r ) >> 1;
	if( x <= mid ) modify( t << 1 , l , mid , x , k );
	else modify( t << 1 | 1 , mid + 1 , r , x , k );
	cnt[t] = cnt[t << 1] + cnt[t << 1 | 1];
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

ll query( int t , int l , int r , int T ){
	if( l == r ) return 1ll * vs[l] * T;
	int mid = ( l + r ) >> 1;
	if( T <= cnt[t << 1 | 1] ) return query( t << 1 | 1 , mid + 1 , r , T );
	else return sum[t << 1 | 1] + query( t << 1 , l , mid , T - cnt[t << 1 | 1] );
}

inline ll check( int x ){
	ans = 0,X = x;
	build( 1 , 1 , vcnt );
	ll res = cnt[1] >= x ? query( 1 , 1 , vcnt , x ) : 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( b[i] == 2 ) modify( 1 , 1 , vcnt , a[i] , -1 );
		else modify( 1 , 1 , vcnt , a[i] , 1 );
		res = max( res , cnt[1] >= x ? query( 1 , 1 , vcnt , x ) : 0 );
	}
	return res;
}

signed main(){
	scanf("%d%d",&n,&k);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),vs[++vcnt] = a[i];
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&b[i]);
	sort( vs + 1 , vs + vcnt + 1 );
	vcnt = unique( vs + 1 , vs + vcnt + 1 ) - ( vs + 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		a[i] = lower_bound( vs + 1 , vs + vcnt + 1 , a[i] ) - vs;
		if( b[i] == 2 ) C[a[i]] ++;
	}
	int l = 1,r = n,ans = -1;
	while( l <= r ){
		int mid = ( l + r ) >> 1;
		if( check( mid ) >= 1ll * mid * k ) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	if( ans == -1 ) ans = 0;
	printf("%d\n",ans);
	return 0;
}