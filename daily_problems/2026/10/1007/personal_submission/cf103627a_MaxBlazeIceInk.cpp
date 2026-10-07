#include<bits/stdc++.h>
using namespace std;

#define MAXN 500005
#define INF (int)1e9

const int off = 250000;

struct node{
	int xu,yu,xv,yv,ans;
}T[MAXN << 2];

multiset<int> xus[MAXN << 2],yus[MAXN << 2],xvs[MAXN << 2],yvs[MAXN << 2];

inline node operator +( node A , node B ){
	node C;
	C.xu = min( A.xu , B.xu );
	C.yu = min( A.yu , B.yu );
	C.xv = min( A.xv , B.xv );
	C.yv = min( A.yv , B.yv );
	C.ans = min( A.ans , B.ans );
	C.ans = min( { C.ans , A.xv + B.xu , A.yu + B.yv } );
	return C;
}

void build( int t , int l , int r ){
	T[t] = node{ INF , INF , INF , INF , INF };
	if( l == r ) return;
	int mid = ( l + r ) >> 1;
	build( t << 1 , l , mid ),build( t << 1 | 1 , mid + 1 , r );
}

void Add( int t , int l , int r , int x , int xu , int yu , int xv , int yv , int c ){
	if( l == r ){
		if( c == 1 )
			xus[t].insert( xu ),yus[t].insert( yu ),xvs[t].insert( xv ),yvs[t].insert( yv );
		else
			xus[t].erase( xus[t].find( xu ) ),
			yus[t].erase( yus[t].find( yu ) ),
			xvs[t].erase( xvs[t].find( xv ) ),
			yvs[t].erase( yvs[t].find( yv ) );
		T[t].xu = xus[t].size() ? *xus[t].begin() : INF;
		T[t].yu = yus[t].size() ? *yus[t].begin() : INF;
		T[t].xv = xvs[t].size() ? *xvs[t].begin() : INF;
		T[t].yv = yvs[t].size() ? *yvs[t].begin() : INF;
		T[t].ans = max( T[t].xu + T[t].xv , T[t].yu + T[t].yv );
		return;
	}
	int mid = ( l + r ) >> 1;
	if( x <= mid ) Add( t << 1 , l , mid , x , xu , yu , xv , yv , c );
	else Add( t << 1 | 1 , mid + 1 , r , x , xu , yu , xv , yv , c );
	T[t] = T[t << 1] + T[t << 1 | 1];
}

int q;

signed main(){
	scanf("%d",&q);
	build( 1 , 1 , 2 * off );
	for( int i = 1 ; i <= q ; i ++ ){
		int ad,op,x,y; scanf("%d%d%d%d",&ad,&op,&x,&y);
		if( op == 1 ){
			Add( 1 , 1 , 2 * off , x - y + off , x , y , INF , INF , ad );
		}
		else{
			Add( 1 , 1 , 2 * off , y - x + off , INF , INF , x , y , ad );
		}
		int ans = T[1].ans;
		if( ans >= INF ) ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}