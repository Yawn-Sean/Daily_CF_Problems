#include<bits/stdc++.h>
using namespace std;

int x,od;

inline int In(){
	int x; scanf("%d",&x);
	return x;
}

map<int,int> M;
inline int Ask( int x ){
	if( M.count( x ) ) return M[x];
	if( x == 1 ) return 0;
	printf("? %d\n",x); fflush( stdout );
	return M[x] = In();
}

int Solve( int l , int r ){
	if( l == r - 1 ){
		if( l % 2 == od ) return l;
		else return r;
	}
	if( l == r ) return l;
	int mid = ( l + r ) >> 1;
	int t = mid % 2 ? mid : mid + 1;
	if( Ask( t ) != od ) return Solve( t , r );
	else return Solve( l , t - 1 );
}

signed main(){
	od = Ask( 2 );
	//起点很重要，两倍原则在 l=1 有边界问题
	printf("! %d\n",Solve( od ? 1 : 2 , (int)1e9 ));
	fflush( stdout );
	return 0;
}