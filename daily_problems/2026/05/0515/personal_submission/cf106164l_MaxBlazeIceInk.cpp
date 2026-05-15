#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int long long
#define INF (int)4e18

int n,q,A,B,X[MAXN],Y[MAXN],C[MAXN],S[MAXN],T[MAXN];
int xs[MAXN],xcnt,ys[MAXN],ycnt,ans[MAXN];

vector<int> M[MAXN],Q[MAXN];

int minn[MAXN];
inline void init(){ for( int i = 1 ; i <= ycnt ; i ++ ) minn[i] = INF; }

inline void chksuf( int x , int k ){ for( ; x <= ycnt ; x += x & -x ) minn[x] = min( minn[x] , k ); }
inline int msuf( int x ){ int ret = INF; for( ; x ; x -= x & -x ) ret = min( ret , minn[x] ); return ret; }
inline void chkpre( int x , int k ){ for( ; x ; x -= x & -x ) minn[x] = min( minn[x] , k ); }
inline int mpre( int x ){ int ret = INF; for( ; x <= ycnt ; x += x & -x ) ret = min( ret , minn[x] ); return ret; }

signed main(){
	scanf("%lld%lld%lld%lld",&n,&q,&A,&B);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld%lld",&X[i],&Y[i],&C[i]);
		ys[++ycnt] = Y[i],xs[++xcnt] = X[i];
	}
	for( int i = 1 ; i <= q ; i ++ )
		scanf("%lld%lld",&S[i],&T[i]),xs[++xcnt] = S[i],ys[++ycnt] = T[i];
	sort( xs + 1 , xs + xcnt + 1 );
	sort( ys + 1 , ys + ycnt + 1 );
	xcnt = unique( xs + 1 , xs + xcnt + 1 ) - ( xs + 1 );
	ycnt = unique( ys + 1 , ys + ycnt + 1 ) - ( ys + 1 );
	for( int i = 1 ; i <= n ; i ++ ){
		X[i] = lower_bound( xs + 1 , xs + xcnt + 1 , X[i] ) - xs;
		Y[i] = lower_bound( ys + 1 , ys + ycnt + 1 , Y[i] ) - ys;
		M[X[i]].emplace_back( i );
	}
	for( int i = 1 ; i <= q ; i ++ ){
		S[i] = lower_bound( xs + 1 , xs + xcnt + 1 , S[i] ) - xs;
		T[i] = lower_bound( ys + 1 , ys + ycnt + 1 , T[i] ) - ys;
		Q[S[i]].emplace_back( i );
	}
	for( int i = 1 ; i <= q ; i ++ ) ans[i] = INF;
	//右上角
	init();
	//A( x0 - x ) + B( y0 - y ) + C
	for( int x = xcnt ; x >= 1 ; x -- ){
		for( int ele : M[x] ) chkpre( Y[ele] , A * xs[x] + B * ys[Y[ele]] + C[ele] );
		for( int ele : Q[x] ) ans[ele] = min( ans[ele] , -A * xs[x] - B * ys[T[ele]] + mpre( T[ele] ) );
	}
	// cerr << ans[1] << "\n";
	//右下角
	init();
	//A( x0 - x ) + B( y - y0 ) + C
	for( int x = xcnt ; x >= 1 ; x -- ){
		for( int ele : M[x] ) chksuf( Y[ele] , A * xs[x] - B * ys[Y[ele]] + C[ele] );
		for( int ele : Q[x] ) ans[ele] = min( ans[ele] , -A * xs[x] + B * ys[T[ele]] + msuf( T[ele] ) );
	}
	//左上角
	init();
	//A( x - x0 ) + B( y0 - y ) + C
	for( int x = 1 ; x <= xcnt ; x ++ ){
		for( int ele : M[x] ) chkpre( Y[ele] , -A * xs[x] + B * ys[Y[ele]] + C[ele] );
		for( int ele : Q[x] ) ans[ele] = min( ans[ele] , A * xs[x] - B * ys[T[ele]] + mpre( T[ele] ) );
	}
	//左下角
	init();
	//A( x - x0 ) + B( y - y0 ) + C
	for( int x = 1 ; x <= xcnt ; x ++ ){
		for( int ele : M[x] ) chksuf( Y[ele] , -A * xs[x] - B * ys[Y[ele]] + C[ele] );
		for( int ele : Q[x] ) ans[ele] = min( ans[ele] , A * xs[x] + B * ys[T[ele]] + msuf( T[ele] ) );
	}
	for( int i = 1 ; i <= q ; i ++ ) printf("%lld\n",ans[i]);
	return 0;
}