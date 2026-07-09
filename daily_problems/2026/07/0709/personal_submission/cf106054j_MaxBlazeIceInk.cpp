#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
int n;
vector<int> E1[MAXN],E2[MAXN];

signed main(){
	scanf("%d",&n);
	map<int,int> M;
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		for( int j = 1 ; j <= x ; j ++ ){
			int t; scanf("%d",&t);
			E1[i].emplace_back( t );
			M[t] ++;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		for( int j = 1 ; j <= x ; j ++ ){
			int t; scanf("%d",&t);
			if( !M[t] ){ puts("N"); return 0; }
			M[t] --;
			E2[i].emplace_back( t );
		}
	}
	for( pair<int,int> p : M ) if( p.second ){ puts("N"); return 0; }
	if( n == 2 ){
		reverse( E1[2].begin() , E1[2].end() );
		for( int ele : E1[2] ) E1[1].emplace_back( ele );
		reverse( E2[2].begin() , E2[2].end() );
		for( int ele : E2[2] ) E2[1].emplace_back( ele );
		if( E1[1] != E2[1] ){
			puts("N");
		return 0;
	}
		
	}
	puts("S");
	return 0;
}