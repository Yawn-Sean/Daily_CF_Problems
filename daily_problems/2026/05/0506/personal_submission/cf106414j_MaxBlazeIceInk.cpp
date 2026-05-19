#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005

int n,X[MAXN],Y[MAXN],p[MAXN];

inline int cmp( int u , int v ){ return Y[u] == Y[v] ? X[u] < X[v] : Y[u] > Y[v]; }

const int D = 200000000;

vector< pair<int,int> > Ans;

inline void solve(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%d%d",&X[i],&Y[i]),p[i] = i;
	sort( p + 1 , p + n + 1 , cmp );
	for( int i = 1 ; i <= n ; i ++ ){
		int I = p[i];
		int xx = X[I],yy = Y[I];
		Ans.emplace_back( make_pair( xx + D , yy + 1 ) );
		Ans.emplace_back( make_pair( xx , yy ) );
	}
	Ans.emplace_back( make_pair( D * 5 , -D * 5 ) );
	Ans.emplace_back( make_pair( -D * 5 , -D * 5 ) );
	Ans.emplace_back( make_pair( -D * 5 , D * 5 ) );
	printf("%d\n",(int)Ans.size());
	for( pair<int,int> ele : Ans ) printf("%d %d\n",ele.first,ele.second); 
	Ans.clear();
}

signed main(){
	int t; scanf("%d",&t);
	while( t -- ) solve();
	return 0;
}