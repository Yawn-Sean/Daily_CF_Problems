#include<bits/stdc++.h>
using namespace std;

#define MAXN 800005

int n,q,l[MAXN],r[MAXN],v[MAXN],L[MAXN],R[MAXN],ql[MAXN],qr[MAXN];
int X[MAXN],xcnt,tr[MAXN],pre[MAXN],Ans[MAXN];
vector< pair<int,int> > T[MAXN];
vector<int> M[MAXN];

inline void add( int x , int k ){ for( ; x <= xcnt ; x += x & -x ) tr[x] += k; }
inline int sum( int x ){ int ret = 0; for( ; x ; x -= x & -x ) ret += tr[x]; return ret; }

void dfs( int x ){
	if( l[x] ) dfs( l[x] ),L[x] = min( L[x] , L[l[x]] ),R[x] = max( R[x] , R[l[x]] );
	if( r[x] ) dfs( r[x] ),L[x] = min( L[x] , L[r[x]] ),R[x] = max( R[x] , R[r[x]] );
}

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d%d%d",&l[i],&r[i],&v[i]);
		L[i] = R[i] = v[i];
	}
	dfs( 1 );
	scanf("%d",&q);
	for( int i = 1 ; i <= q ; i ++ ) scanf("%d%d",&ql[i],&qr[i]),X[++xcnt] = ql[i],X[++xcnt] = qr[i];
	for( int i = 1 ; i <= n ; i ++ ) X[++xcnt] = L[i],X[++xcnt] = R[i];
	sort( X + 1 , X + xcnt + 1 ),xcnt = unique( X + 1 , X + xcnt + 1 ) - ( X + 1 );
	for( int i = 1 ; i <= n ; i ++ ) L[i] = lower_bound( X + 1 , X + xcnt + 1 , L[i] ) - X;
	for( int i = 1 ; i <= n ; i ++ ) R[i] = lower_bound( X + 1 , X + xcnt + 1 , R[i] ) - X;
	for( int i = 1 ; i <= q ; i ++ ){
		ql[i] = lower_bound( X + 1 , X + xcnt + 1 , ql[i] ) - X;
		qr[i] = lower_bound( X + 1 , X + xcnt + 1 , qr[i] ) - X;
	}
	//三种情况 R[x] < l,L[x] > r,l <= L[x] <= R[x] <= r
	for( int i = 1 ; i <= n ; i ++ ) pre[L[i]] ++;
	for( int i = xcnt ; i >= 1 ; i -- ) pre[i] += pre[i + 1];
	for( int i = 1 ; i <= q ; i ++ ) Ans[i] += pre[qr[i] + 1];
	memset( pre , 0 , sizeof( pre ) );
	for( int i = 1 ; i <= n ; i ++ ) pre[R[i]] ++;
	for( int i = 1 ; i <= xcnt ; i ++ ) pre[i] += pre[i - 1];
	for( int i = 1 ; i <= q ; i ++ ) Ans[i] += pre[ql[i] - 1];
	memset( pre , 0 , sizeof( pre ) );
	for( int i = 1 ; i <= q ; i ++ ) T[ql[i]].emplace_back( make_pair( qr[i] , i ) );
	for( int i = 1 ; i <= n ; i ++ ) M[L[i]].emplace_back( R[i] );
	for( int i = xcnt ; i >= 1 ; i -- ){
		for( int p : M[i] ) add( p , 1 );
		for( pair<int,int> p : T[i] ) Ans[p.second] += sum( p.first );
	}
	for( int i = 1 ; i <= q ; i ++ ) printf("%d\n",2 * ( n - Ans[i] ) + 1);
	return 0;
}