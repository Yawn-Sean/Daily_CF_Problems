#include<bits/stdc++.h>
using namespace std;

#define MAXN 20

typedef long long ll;
const int V = ( 1 << 22 ) + 5;

int n,q,a[1 << MAXN],cov[V],len[V];
ll sum[V];

inline int read(){
	int x = 0; char ch = getchar();
	while( ch < '0' || ch > '9' ) ch = getchar();
	while( ch >= '0' && ch <= '9' ) x = x * 10 + ch - 48,ch = getchar();
	return x;
}

void build( int t , int l , int r ){
	len[t] = r - l + 1,cov[t] = -1;
	if( l == r ){ sum[t] = a[l]; return; }
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

inline void update( int t , int k ){
	cov[t] = k,sum[t] = 1ll * k * len[t];
}

inline void push_down( int t ){
	if( cov[t] != -1 ) update( t << 1 , cov[t] ),update( t << 1 | 1 , cov[t] );
	cov[t] = -1;
}

//[L,R] 是被拆分出来的子区间，低位还没有异或 k

void modify( int t , int l , int r , int L , int R , int v , int k , int bit ){
	if( L <= l && r <= R ){ update( t , v ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( k >> bit & 1 ){
		if( L <= mid ) modify( t << 1 | 1 , mid + 1 , r , L ^ ( 1 << bit ) , min( mid , R ) ^ ( 1 << bit ) , v , k , bit - 1 );
		if( R > mid ) modify( t << 1 , l , mid , max( L , ( mid + 1 ) ) ^ ( 1 << bit ) , R ^ ( 1 << bit ) , v , k , bit - 1 );
	}
	else{
		if( L <= mid ) modify( t << 1 , l , mid , L , R , v , k , bit - 1 );
		if( R > mid ) modify( t << 1 | 1 , mid + 1 , r , L , R , v , k , bit - 1 );
	}
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

ll query( int t , int l , int r , int L , int R , int k , int bit ){
	if( L <= l && r <= R ) return sum[t];
	push_down( t );
	int mid = ( l + r ) >> 1;
	ll res = 0;
	if( k >> bit & 1 ){
		if( L <= mid ) res += query( t << 1 | 1 , mid + 1 , r , L ^ ( 1 << bit ) , min( mid , R ) ^ ( 1 << bit ) , k , bit - 1 );
		if( R > mid ) res += query( t << 1 , l , mid , max( L , ( mid + 1 ) ) ^ ( 1 << bit ) , R ^ ( 1 << bit ) , k , bit - 1 );
	}
	else{
		if( L <= mid ) res += query( t << 1 , l , mid , L , R , k , bit - 1 );
		if( R > mid ) res += query( t << 1 | 1 , mid + 1 , r , L , R , k , bit - 1 );
	}
	return res;
}

signed main(){
	n = read();
	for( int i = 0 ; i < 1 << n ; i ++ ) a[i] = read();
	build( 1 , 0 , ( 1 << n ) - 1 );
	q = read();
	for( int i = 1 ; i <= q ; i ++ ){
		// cerr << "asd\n";
		int op = read(),l = read(),r = read(),k = read();
		if( op == 1 ){
			int v = read();
			modify( 1 , 0 , ( 1 << n ) - 1 , l , r , v , k , n - 1 );
		}
		else{
			ll ans = query( 1 , 0 , ( 1 << n ) - 1 , l , r , k , n - 1 );
			printf("%lld\n",ans);
		}
	}
	return 0;
}