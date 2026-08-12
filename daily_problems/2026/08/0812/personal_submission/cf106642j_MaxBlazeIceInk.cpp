#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,m,a[MAXN],L[MAXN],R[MAXN],st[MAXN],top;
vector<int> pos[MAXN];

int rev[MAXN << 2],sum[MAXN << 2],len[MAXN << 2];

void build( int t , int l , int r ){
	len[t] = r - l + 1; if( l == r ) return;
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

inline void update( int t ){ sum[t] = len[t] - sum[t],rev[t] ^= 1; }
inline void push_down( int t ){
	if( rev[t] ) update( t << 1 ),update( t << 1 | 1 );
	rev[t] = 0;
}

void modify( int t , int l , int r , int L , int R ){
	if( L <= l && r <= R ){ update( t ); return; }
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( L <= mid ) modify( t << 1 , l , mid , L , R );
	if( R > mid ) modify( t << 1 | 1 , mid + 1 , r , L , R );
	sum[t] = sum[t << 1] + sum[t << 1 | 1];
}

int query( int t , int l , int r , int L , int R ){
	if( L <= l && r <= R ) return sum[t];
	push_down( t );
	int mid = ( l + r ) >> 1;
	if( R <= mid ) return query( t << 1 , l , mid , L , R );
	if( L > mid ) return query( t << 1 | 1 , mid + 1 , r , L , R );
	return query( t << 1 , l , mid , L , R ) + query( t << 1 | 1 , mid + 1 , r , L , R );
}

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]),pos[a[i]].emplace_back( i );
	for( int i = 1 ; i <= n ; i ++ ){
		while( top && a[i] <= a[st[top]] ) R[st[top]] = i,top --;
		st[++top] = i;
	} while( top ) R[st[top]] = n + 1,top --;
	for( int i = n ; i >= 1 ; i -- ){
		while( top && a[i] < a[st[top]] ) L[st[top]] = i,top --;
		st[++top] = i;
	} while( top ) L[st[top]] = 0,top --;
	build( 1 , 1 , n );
	long long ans = 0;
	for( int v = 1 ; v <= n ; v ++ ){
		vector<int> Odds,Evens;
		for( int ele : pos[v] ){
			//f[l] 表示 [l,r] 是否合法，则每次的工作是取反
			modify( 1 , 1 , n , 1 , ele );
			ans += 1ll * ( R[ele] - ele ) * query( 1 , 1 , n , L[ele] + 1 , ele );
		}
		for( int ele : pos[v] ) modify( 1 , 1 , n , 1 , ele );
	}
	printf("%lld\n",ans);
	for( int i = 1 ; i <= n ; i ++ ) pos[i].clear();
	for( int i = 1 ; i <= n * 4 ; i ++ ) len[i] = rev[i] = sum[i] = 0;
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}