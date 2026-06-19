#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000005
int n,k,pos[MAXN];

char s[MAXN];
pair<int,int> p[MAXN];

signed main(){
	scanf("%d%d%s",&n,&k,s + 1);
	for( int i = 1 ; i <= n ; i ++ ) p[i] = make_pair( s[i] , i );
	sort( p + 1 , p + n + 1 );
	for( int i = 1 ; i <= n ; i ++ ) pos[i] = p[i].second;
	vector< pair<int,int> > A;
	if( pos[1] == 1 ){
		A.emplace_back( make_pair( s[1] , 0 ) );	
		for( int i = 2 ; i <= n ; i += 2 )
			A.emplace_back( make_pair( s[i] , i ) );
	}
	else{
		for( int i = pos[1] ; i <= n ; i += 2 )
			A.emplace_back( make_pair( s[i] , i ) );
		for( int i = pos[1] - 1 ; i >= 1 ; i -= 2 )
			A.emplace_back( make_pair( i == 1 ? s[i] : s[i - 1] , i - 1 ) );
	}
	sort( A.begin() , A.end() );
	for( pair<int,int> p : A ){
		int e = p.second;
		for( int i = 1 ; i <= k ; i ++ ){
			if( e ) printf("%c",s[e]);
			if( e < n ) printf("%c",s[e + 1]);
		}
	}
	return 0;
}