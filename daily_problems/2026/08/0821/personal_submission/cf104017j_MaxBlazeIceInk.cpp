#include<bits/stdc++.h>
using namespace std;

#define int long long

int w,l;
vector<int> A;

inline void sieve( int x , int y ){
	for( int i = 1 ; i * i <= x ; i ++ ){
		if( x % i == 0 ){
			if( y % i == 0 ) A.emplace_back( i );
			if( y % ( x / i ) == 0 ) A.emplace_back( x / i );
		}
	}
}

inline void solve(){
	scanf("%lld%lld",&w,&l);
	sieve( w - 1 , l - 1 ),sieve( w , l - 2 ),sieve( w - 2 , l );
	if( ( w + l ) % 2 ) A.emplace_back( 2 );
	sort( A.begin() , A.end() );
	A.erase( unique( A.begin() , A.end() ) , A.end() );
	printf("%lld\n",(int)A.size());
	for( int ele : A ) printf("%lld ",ele); puts("");
	A.clear();
}

signed main(){
	int t; scanf("%lld",&t);
	while( t -- ) solve();
	return 0;
}