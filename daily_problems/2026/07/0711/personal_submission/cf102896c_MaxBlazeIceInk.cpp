#include<bits/stdc++.h>
using namespace std;

#define MAXN 30

int n;
vector<int> E[MAXN],Ans[MAXN];

vector<int> Merge( vector<int> A , vector<int> B ){
	int sizA = (int)A.size(),sizB = (int)B.size();
	vector<int> Ans;
	for( int i = 0 ; i < sizA ; i ++ ){
		Ans.emplace_back( A[i] );
		if( i % 2 == 0 )
			for( int j = 0 ; j < sizB ; j ++ ) Ans.emplace_back( B[j] );
		else
			for( int j = sizB - 1 ; j >= 0 ; j -- ) Ans.emplace_back( B[j] );
	}
	return Ans;
}

void dfs( int x , int fa ){
	Ans[x].emplace_back( x );
	for( int v : E[x] ){
		if( v == fa ) continue;
		dfs( v , x );
		Ans[x] = Merge( Ans[x] , Ans[v] );
	}
}

signed main(){
	scanf("%d",&n);
	for( int i = 2 ; i <= n ; i ++ ){
		int x; scanf("%d",&x);
		E[x].emplace_back( i );
	}
	dfs( 1 , 0 );
	printf("%d\n",(int)Ans[1].size() - 1);
	for( int i = 1 ; i < (int)Ans[1].size() ; i ++ ) printf("%d ",Ans[1][i]); 
	return 0;
}