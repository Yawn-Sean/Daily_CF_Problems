#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n;

map< int , set<int> > X,Y;
multiset<int> sx,sy;
pair<int,int> P[MAXN];

inline int Abs( int x ){ return x < 0 ? -x : x; }

signed main(){
	scanf("%lld",&n);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%lld%lld",&P[i].first,&P[i].second);
		X[P[i].first].insert( i ),Y[P[i].second].insert( i );
		sx.insert( P[i].first ),sy.insert( P[i].second );
	}
	for( int i = 1 ; i <= n / 4 ; i ++ ){
		int xm = *sx.begin(),xM = *sx.rbegin(),ym = *sy.begin(),yM = *sy.rbegin();
		set<int> bound;
		for( int ele : X[xm] ) bound.insert( ele );
		for( int ele : X[xM] ) bound.insert( ele );
		for( int ele : Y[ym] ) bound.insert( ele );
		for( int ele : Y[yM] ) bound.insert( ele );
		for( int ele : bound ){
			if( sx.find( P[ele].first ) != sx.end() )
				sx.erase( sx.find( P[ele].first ) );
			if( sy.find( P[ele].second ) != sy.end() )
				sy.erase( sy.find( P[ele].second ) );
			
			X[P[ele].first].erase( ele );
			Y[P[ele].second].erase( ele );
		}
		assert( bound.size() >= 4 );
		if( i == n / 4 ){
			set<int>::iterator it = bound.begin();
			int i1 = *it; it ++; int i2 = *it; it ++; int i3 = *it;
			int dx1 = P[i1].first - P[i2].first;
			int dy1 = P[i1].second - P[i2].second;
			int dx2 = P[i1].first - P[i3].first;
			int dy2 = P[i1].second - P[i3].second;
			printf("%lld\n",Abs( dx2 * dy1 - dx1 * dy2 ));
			return 0;
		}
	}
	return 0;
}