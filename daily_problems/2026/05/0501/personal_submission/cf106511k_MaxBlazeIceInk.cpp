#include<bits/stdc++.h>
using namespace std;

#define int long long

int k;
vector<int> ans;

inline void sslice( int x , int t ){
	//神人递归创造者
	if( x <= 20 ){
		ans.emplace_back( 7000000 );
		ans.emplace_back( 8000000 );
		for( int i = 1 ; i <= x ; i ++ ) ans.emplace_back( -15000000 );
		return;
	}
	int A = (int)( pow( x , 0.33333 ) );
	if( A ){
		int f = 0;
		for( int i = 1 ; ; i ++ ){
			if( i * ( i - 1 ) / 2 * A <= x ){
				f = i;
			}
			else break;
		}
		for( int i = 1 ; i <= f ; i ++ ) ans.emplace_back( -t );
		for( int i = 1 ; i <= A ; i ++ ) ans.emplace_back( 2 * t );
		x -= f * ( f - 1 ) / 2 * A;
	}
	sslice( x , 2 * t + 1 );
}

signed main(){
	scanf("%lld",&k);
	int n = 0;
	while( ( n + 1 ) * n * ( n - 1 ) / 6 <= k ) n ++;
	for( int i = 1 ; i <= n ; i ++ ) ans.emplace_back( 0 );
	int rem = k - n * ( n - 2 ) * ( n - 1 ) / 6;
	sslice( rem , 1 );
	printf("%lld\n",(int)ans.size());
	for( int ele : ans ) printf("%lld ",ele);
	return 0;
}