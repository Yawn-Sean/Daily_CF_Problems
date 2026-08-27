#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,p[MAXN];
map< int , vector<int> > M;

inline vector<int> solve_perm( int n ){
	if( n == 1 ){
		vector<int> A; A.emplace_back( 1 );
		return A;
	}
	if( M.count( n ) ) return M[n];
	vector<int> A = solve_perm( ( n + 1 ) / 2 ),B = solve_perm( n / 2 );
	vector<int> res;
	for( int ele : A ) res.emplace_back( ele * 2 - 1 );
	for( int ele : B ) res.emplace_back( ele * 2 );
	return M[n] = res;
}

inline void solve(){
	scanf("%d",&n);
	vector<int> T = solve_perm( n );
	for( int i = 1 ; i <= n ; i ++ , puts("") ){
		for( int j = 1 ; j <= n ; j ++ ){
			printf("%d ",( T[i - 1] - 1 ) * n + T[j - 1]);
		}
	}
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}