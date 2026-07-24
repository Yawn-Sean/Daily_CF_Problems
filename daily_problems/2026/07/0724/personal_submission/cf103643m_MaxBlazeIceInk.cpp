#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,q,m,A[MAXN],B[MAXN],deg[MAXN],ans[MAXN];
vector<int> E[MAXN],T[MAXN];

signed main(){
	scanf("%d%d%d",&n,&m,&q);
	map< pair<int,int> , int > M;
	for( int i = 1 ; i <= m ; i ++ ){
		int u,v; scanf("%d%d",&u,&v);
		E[u].emplace_back( v ),E[v].emplace_back( u );
		deg[u] ++,deg[v] ++;
	}
	for( int i = 1 ; i <= n ; i ++ ) sort( E[i].begin() , E[i].end() );
	for( int i = 1 ; i <= q ; i ++ ){
		int u,v; scanf("%d%d",&u,&v); if( u > v ) swap( u , v );
		A[i] = u,B[i] = v;
	}
	if( n <= 4 ){
		for( int i = 1 ; i <= q ; i ++ ) printf("%d\n",n - 2);
		return 0;
	}
	//vector 重名之神
	vector<int> C;
	for( int i = 1 ; i <= n ; i ++ ){
		if( deg[i] >= n - 4 ){
			C.emplace_back( i );
			//对每个可能成为答案的点统计补集
			int pnt = 0,siz = E[i].size();
			for( int j = 1 ; j <= n ; j ++ ){
				if( i == j ) continue;
				while( pnt < siz && E[i][pnt] < j ) pnt ++;
				if( pnt == siz || E[i][pnt] > j ){
					T[i].emplace_back( j );
					// cerr << i << " " << j << "\n";
				}
			}
			assert( T[i].size() <= 3 );
		}
	}
	for( int ele : C ){
		//只有 ele 可以成为答案
		for( int i = 1 ; i <= q ; i ++ ){
			if( A[i] == ele || B[i] == ele ) continue;
			int c = n - 1 - deg[ele];
			// cerr << "?" << ele << " " << c << "\n";
			for( int u : T[ele] ){
				if( A[i] == u ) c --;
				if( B[i] == u ) c --;
			}
			if( c <= 1 ) ans[i] ++;
		}
	}
	for( int i = 1 ; i <= q ; i ++ ) printf("%d\n",ans[i]);
	return 0;
}