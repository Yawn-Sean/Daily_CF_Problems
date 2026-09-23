#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;

const int B = 325,V = 100000;

int n,q,a[MAXN],b[MAXN],L[MAXN],R[MAXN],bel[MAXN],tr1[MAXN],tr2[MAXN],cnt1[MAXN],cnt2[MAXN];
ll Ans[MAXN];

struct node{
	int l,r,k,id;
};

vector<node> N;

inline bool cmp( node A , node B ){
	if( bel[A.l] == bel[B.l] ) return A.r < B.r;
	return bel[A.l] < bel[B.l];
}

inline void add( int *tr , int x , int k ){ for( ; x <= V ; x += x & -x ) tr[x] += k; }
inline int sum( int *tr , int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

//上界是多少？
inline void Add( int x ){ if( a[x] <= V ) cnt1[a[x]] ++,add( tr1 , a[x] , 1 ); if( b[x] <= V ) cnt2[b[x]] ++,add( tr2 , b[x] , 1 ); }
inline void Del( int x ){ if( a[x] <= V ) cnt1[a[x]] --,add( tr1 , a[x] , -1 ); if( b[x] <= V ) cnt2[b[x]] --,add( tr2 , b[x] , -1 ); }

signed main(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&a[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d",&b[i]);
	for( int i = 1 ; i <= n ; i ++ ) bel[i] = ( i - 1 ) / B + 1;
	for( int i = 1 ; i <= n ; i ++ ) R[bel[i]] = i;
	for( int i = n ; i >= 1 ; i -- ) L[bel[i]] = i;
	for( int i = 1 ; i <= q ; i ++ ){
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		N.emplace_back( node{ l , r , k , i } );
	}
	sort( N.begin() , N.end() , cmp );
	int R = 0,L = 1;
	for( node qq : N ){
		int l = qq.l,r = qq.r,k = qq.k,id = qq.id;
		while( L < l ) Del( L ),L ++;
		while( L > l ) L --,Add( L );
		while( R < r ) R ++,Add( R );
		while( R > r ) Del( R ),R --;
		ll ans = 0,B = int( sqrt( k ) ) - 1; while( ( B + 1 ) * ( B + 1 ) <= k ) B ++;
		for( int i = 1 ; ; i ++ ){
			if( i * i > k ) break;
			ans += 1ll * cnt1[i] * sum( tr2 , k / i );
			ans += 1ll * cnt2[i] * max( 0 , sum( tr1 , k / i ) - sum( tr1 , B ) );
		}
		Ans[id] = ans;
	}
	for( int i = 1 ; i <= q ; i ++ )
		printf("%lld\n",Ans[i]);
	return 0;
}