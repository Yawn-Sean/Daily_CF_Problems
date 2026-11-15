#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 10005

int n,f[MAXN];
vector<int> ans;

inline bool judge( int x , int c ){
	if( x < 10 ) return x == 4;
	if( x % 2 || x % 4 == 2 || x % 5 == 1 || x % 5 == 2 || x % 5 == 3 ) return 0; 
	if( c == 2 && ( x % 10 == 0 || x % 10 == 4 ) ) return 1;
	return judge( x / 10 , c + 1 );
}

inline vector<int> gett( int x ){
	if( x % 2 ){
		vector<int> ans;
		for( int i = 1 ; i <= x ; i ++ ) ans.emplace_back( 1 );
		return ans;
	}
	if( x % 4 == 2 ){
		vector<int> ans;
		for( int i = 1 ; i <= x / 2 ; i ++ ) ans.emplace_back( 2 );
		return ans;
	}
	if( x % 5 == 1 ){
		vector<int> ans;
		for( int i = 1 ; i <= x / 5 ; i ++ ) ans.emplace_back( 5 );
		ans.emplace_back( 1 );
		return ans;
	}
	if( x % 5 == 2 ){
		vector<int> ans;
		for( int i = 1 ; i <= x / 5 ; i ++ ) ans.emplace_back( 5 );
		ans.emplace_back( 2 );
		return ans;
	}
	if( x % 5 == 3 ){
		vector<int> ans;
		for( int i = 1 ; i <= x / 5 ; i ++ ) ans.emplace_back( 5 );
		ans.emplace_back( 1 ),ans.emplace_back( 2 );
		return ans;
	}
	if( x < 10 ){
		if( x == 1 ) return vector<int>( { 1 } );	
		if( x == 2 ) return vector<int>( { 2 } );	
		if( x == 3 ) return vector<int>( { 2 , 1 } );	
		if( x == 5 ) return vector<int>( { 5 } );	
		if( x == 6 ) return vector<int>( { 5 , 1 } );	
		if( x == 7 ) return vector<int>( { 5 , 2 } );	
		if( x == 8 ) return vector<int>( { 5 , 2 , 1 } );
		if( x == 9 ) return vector<int>( { 5 , 2 , 1 , 1 } );	
	}
	vector<int> ans = gett( x / 10 );
	for( int &ele : ans ) ele *= 10;
	if( x % 10 ) ans.emplace_back( 2 ),ans.emplace_back( 2 );
	return ans;
}

signed main(){
	scanf("%lld",&n);
	if( judge( n , 0 ) ){ puts("splittable"); return 0; }
	vector<int> ans = gett( n );
	printf("%lld\n",ans.size());
	for( int ele : ans ) printf("%lld ",ele);
	return 0;
}